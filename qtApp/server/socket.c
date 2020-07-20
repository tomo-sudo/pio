#include "socket.h"

void serverSock()
{
	const int port = 8888;
	void serveForClient(void *arg);
      	struct sockaddr_in clientSock;
	struct pthreadData pData;
   	pthread_t pt = 0;
      	socklen_t sinSize = sizeof(struct sockaddr_in);
       	struct sockaddr_in clientAddr;
     
	int clientFd = 0;
       	int servSock = socket(AF_INET, SOCK_STREAM, 0);
     
	memset(&clientSock, 0, sizeof(clientSock));
	memset(&pData, 0, sizeof(pData));
	clientSock.sin_family = AF_INET;
	clientSock.sin_port = htons(port);
	clientSock.sin_addr.s_addr = INADDR_ANY;
    
       	bind(servSock, (struct sockaddr *)&clientSock, sizeof(struct sockaddr));
     
	if(listen(servSock, 1) < -1)
	{
	     	printf("131\n");
		return;
	}

       	printf("Server is running===========================================\n");
     
	while(1)
	{
		clientFd = accept(servSock, (struct sockaddr *)&clientAddr, &sinSize);
	   	pData.clientAddr = clientAddr;
		pData.sockFd = clientFd;
	       	pthread_create(&pt, NULL, (void *)serveForClient, (void *)&pData);
     	}
}
//
//offer services only when the user is registered
void serveForClient(void *arg)
{
	char clientIP[INET_ADDRSTRLEN];
       	struct userBaseInfo recvBuf;
       	struct userBaseInfo sendBuf;


   	struct pthreadData *pData = (struct pthreadData*)arg;
      	int clientFd = pData->sockFd;
     
	memset(clientIP, 0, sizeof(clientIP));
    
	bzero(&recvBuf, sizeof(recvBuf));	


//	strncpy(sendBuf.sex, "male1", strlen("male1") + 1);

	read(clientFd, &recvBuf, sizeof(struct userBaseInfo));
       	inet_ntop(AF_INET, &pData->clientAddr.sin_addr, clientIP, INET_ADDRSTRLEN);
	//strncpy(clientIP, inet_lnaof(&pData->clientAddr.sin_addr.s_addr), sizeof(clientIP));
     

	//int nameNum = strlen(recvBuf.registerName) + 1;
	//printf("number of name is %d\n", nameNum);
	//strncpy(sendBuf.registerName, recvBuf.registerName, nameNum);


	printf("------start write---------\n");
	write(clientFd, &sendBuf, sizeof(struct userBaseInfo));

	printf("%s\n", recvBuf.registerName);
	printf("%s\n", recvBuf.sex);

	close(clientFd);
	pthread_exit(0);
 }
