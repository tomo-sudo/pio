#pragma once
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "string.h"

struct pthreadData
{
	struct sockaddr_in clientAddr;
	int sockFd;
};

struct userBaseInfo
{
	char registerName[20];
	char definedName[20];
	char sex[10];
	char password[20];
};
