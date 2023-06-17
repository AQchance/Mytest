#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

int main()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	fputs("ipaddress: ", stdout);
	char host[64];
	scanf("%s", host);

	fputs("port: ", stdout);
	int port;
	scanf("%d", &port);

	SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	struct sockaddr_in sockAddr;
	memset(&sockAddr, 0, sizeof(sockAddr));
	sockAddr.sin_family = PF_INET;
	sockAddr.sin_addr.s_addr = inet_addr(host);
	sockAddr.sin_port = htons(port);
	connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));

	char msg[MAXBYTE];
	fputs("input serve second: ", stdout);
	int time;
	scanf("%d", &time);
	snprintf(msg, MAXBYTE, "%d\n", time);
	send(sock, msg, strlen(msg) + 1, 0);

	closesocket(sock);

	WSACleanup();

	return 0;
}

