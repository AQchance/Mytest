#include <stdio.h>
#include <winsock2.h>
#include <unistd.h>
#include <time.h>
#pragma comment (lib, "ws2_32.lib")

int main()
{
	WSADATA wsaData;
	WSAStartup( MAKEWORD(2, 2), &wsaData);

	fputs("port: ", stdout);
	int port;
	scanf("%d", &port);

	SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	struct sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));
	sockAddr.sin_family = PF_INET;
	sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	sockAddr.sin_port = htons(port);
	bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));

	listen(servSock, 20);

	SOCKADDR clntAddr;
	int nSize = sizeof(SOCKADDR);

	for (;;) {
		SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);
		char recvBuf[MAXBYTE] = {0};
		recv(clntSock, recvBuf, MAXBYTE, 0);
		int sec;
		time_t tmval;
		struct tm *tmptr;
		sscanf(recvBuf, "%d", &sec);
		if (sec > 0) {
			tmval = time(0);
			tmptr = localtime(&tmval);
			printf("[%02d:%02d:%02d] server will sleep %d seconds\n",
					tmptr->tm_hour, tmptr->tm_min,
					tmptr->tm_sec, sec);
			sleep(sec);
			tmval = time(0);
			tmptr = localtime(&tmval);
			printf("[%02d:%02d:%02d] server is wake up\n",
					tmptr->tm_hour, tmptr->tm_min, tmptr->tm_sec);
		}
		closesocket(clntSock);
	}

	closesocket(servSock);

	WSACleanup();

	return 0;
}

