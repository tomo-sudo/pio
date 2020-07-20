#pragma once

#include <fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdbool.h>           
#include<mysql/mysql.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

//genernal use
int openF(char *name);
int openFlash(char *name);


int rdLine(int fd, void *pstr);  //here char *pstr equals to char pstr[]
int rdOnceRd(int fd, void *pstr);  //here char *pstr equals to char pstr[]


MYSQL *mysqlConn;
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
