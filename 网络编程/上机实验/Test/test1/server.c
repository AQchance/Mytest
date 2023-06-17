#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

#define LISTENQ 1024
#define BUFSIZE 1024

int open_listenfd(int port);
void service(int connfd);
void sigchld_handler(int sig);

static int pcnt;

int main(int argc, char *argv[])
{
	int listenfd, connfd, port;
	unsigned int clientlen;
	struct sockaddr_in clientaddr;
	pid_t pid;

	if (argc != 2) {
		fprintf(stderr, "%s <port>\n", argv[0]);
		exit(-1);
	}
	port = atoi(argv[1]);

	signal(SIGCHLD, sigchld_handler);
	if ((listenfd = open_listenfd(port)) == -1) {
		fprintf(stderr, "%s\n", strerror(errno));
		exit(-1);
	}
	for (;;) {
		clientlen = sizeof(clientaddr);
		do {
			connfd = accept(listenfd,
				(struct sockaddr *)&clientaddr.sin_addr.s_addr,
				&clientlen);
		} while (connfd == -1 && errno == EINTR);

		if (connfd == -1) {
			fprintf(stderr, "%s\n", strerror(errno));
			exit(-1);
		}

		if ((pid = fork()) == -1) {
			fprintf(stderr, "%s\n", strerror(errno));
		} else {
			pcnt++;
			if (pid == 0) {
				close(listenfd);
				service(connfd);
				close(connfd);
				exit(EXIT_SUCCESS);
			}
		}
		close(connfd);
	}
	exit(EXIT_SUCCESS);
}

void service(int connfd)
{
	char buf[BUFSIZE];
	int seconds;
	time_t tmval;
	const struct tm *tmptr;

	read(connfd, buf, BUFSIZE);
	sscanf(buf, "%d", &seconds);
	if (seconds > 0) {
		tmval = time(0);
		tmptr = localtime(&tmval);
		printf("process %d: %d seconds. total child_pid: %d\n",getpid(), seconds, pcnt);
		sleep(seconds);
	}
}

void sigchld_handler(int sig)
{
	pid_t pid;
	time_t tmval;
	const struct tm *tmptr;

	while ((pid = (waitpid(-1, NULL, WNOHANG))) > 0) {
		tmval = time(0);
		tmptr = localtime(&tmval);
		printf("process %d exited. total child_pid: %d\n",pid, --pcnt);
	}
	signal(SIGCHLD, sigchld_handler);
}

int open_listenfd(int port)
{
	int listenfd, optval = 1;
	struct sockaddr_in serveraddr;

	/* creat socket */
	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return -1;

	/* setsocket */
	if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR,
				(const void *)&optval, sizeof(int)) < 0)
		return -1;

	
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons((unsigned short) port);
	
	/*bind*/
	if (bind(listenfd, (struct sockaddr *)&serveraddr,
				sizeof(serveraddr)) < 0)
		return -1;

	if (listen(listenfd, LISTENQ) < 0)
		return -1;
	return listenfd;
}
