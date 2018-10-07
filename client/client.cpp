// client.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <WinSock2.h>

void ErrorHandling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 3)
	{
		printf("Usage : %s <IP><port>\n", argv[0]);
		exit(1);
	}

	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		ErrorHandling("WSAStartup() error");
	}

	SOCKET hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET)
	{
		ErrorHandling("socket() error");
	}

	SOCKADDR_IN servAddr;
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(argv[1]);
	servAddr.sin_port = htons(atoi(argv[2]));
	
	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
	{
		ErrorHandling("connect() error");
	}

	char message[30];
	int strLen = recv(hSocket, message, sizeof(message) - 1, 0);
	if (strLen == -1)
	{
		ErrorHandling("recv() error");
	}
	printf("MEssage from server: %s \n", message);

	closesocket(hSocket);
	WSACleanup();


	return 0;
}

