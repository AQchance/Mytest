#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>

int open_clientfd(char *hostname, int port);

int main(int argc, char *argv[])
{
	int clientfd, port;
	char *host, *seconds;

	if (argc != 4) {
		fprintf(stderr, "usage: %s <host> <port> <seconds>\n", argv[0]);
		exit(-1);
	}
	host = argv[1];
	port = atoi(argv[2]);
	seconds = argv[3];

	if ((clientfd = open_clientfd(host, port)) == -1) {
		fprintf(stderr, "%s\n", strerror(errno));
		exit(-1);
	}
	write(clientfd, seconds, strlen(seconds));
	close(clientfd);
	exit(EXIT_SUCCESS);
}

int open_clientfd(char *hostname, int port)
{
	int clientfd;
	struct hostent *hp;
	struct sockaddr_in serveraddr;

	if ((clientfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return -1;

	if ((hp = gethostbyname(hostname)) == NULL)
		return -2;
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	memcpy((char *)&serveraddr.sin_addr.s_addr,
			(char *)hp->h_addr_list[0],
			hp->h_length);
	serveraddr.sin_port = htons(port);

	/*connect */
	if (connect(clientfd, (struct sockaddr *)&serveraddr,
				sizeof(serveraddr)) < 0)
		return -1;
	return clientfd;
}
