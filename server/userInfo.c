#include "userInfo.h"

int main(int argc, char *argv[])
{

	void printMysqlErr(const char *);	
	bool dbConn();

	bool connState = dbConn();
	if(!connState)
	{
		printMysqlErr("conn failed");	
		return -1;
	}




	void serverSock();
	serverSock();

	return 0;
}

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
	void queryUserNormInfoModel(char *registerName, struct userBaseInfo *sendBuf);
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

	queryUserNormInfoModel("zhang", &sendBuf);

	printf("------start write---------\n");
	write(clientFd, &sendBuf, sizeof(struct userBaseInfo));

	printf("%s\n", recvBuf.registerName);
	printf("%s\n", recvBuf.sex);

	close(clientFd);
	pthread_exit(0);
 }



void queryUserNormInfoModel(char *registerName, struct userBaseInfo *sendBuf)
{
	bool executeSql(const char *);
	void showUserInfo(const struct userBaseInfo *usrInfo);

	char tmp[1024];
	bzero(tmp, sizeof(tmp));
	sprintf(tmp, "select * from userBaseInfo where registerName=\'%s\';", registerName);
	if(!executeSql(tmp))
	{
		printf("460\n");
		return;
	}
	MYSQL_RES *resultSet = mysql_store_result(mysqlConn);
	int rows = mysql_num_rows(resultSet);
	if(rows == 0)
	{
		printf("648\n");
		return;
	}

	MYSQL_ROW record = mysql_fetch_row(resultSet);
        mysql_free_result(resultSet); 

	bzero(sendBuf, sizeof(sendBuf));
	strncpy(sendBuf->registerName, record[0], strlen(record[0]) + 1);
	strncpy(sendBuf->definedName, record[1], strlen(record[1]) + 1);
	strncpy(sendBuf->sex, record[2], strlen(record[2]) + 1);

	showUserInfo(sendBuf);
}


bool dbConn()
{
	const char *hostName = NULL;  
	const char *userName = "root";
	const char *passWd = "123456";
	const char *dbName = "userInfo";
	const char *unixSocket = NULL;   
	const unsigned int dbPort = 0;  
	const int clientFlag = 0;   

	void printMysqlErr(const char *);
	bool executeSql(const char *);

	mysqlConn = mysql_init(NULL);	


	if(mysql_real_connect(mysqlConn, hostName, userName, passWd, dbName, dbPort, unixSocket, clientFlag) == NULL) 
		return false;

	char queryTemp[40] = "set names utf8";

	if(!executeSql(queryTemp))
		return false;

	return true; 
}

bool executeSql(const char *sqlQuery)
{

	if(mysql_real_query(mysqlConn, sqlQuery, strlen(sqlQuery)))
		return false;          
	else
					
		return true;                 
}

void printMysqlErr(const char *errInfo)
{
	if(errInfo)
		printf("%s: %s\n", errInfo, mysql_error(mysqlConn));
	else
		printf(mysql_error(mysqlConn));
}

void showUserInfo(const struct userBaseInfo *usrInfo)
{
	printf("registerName: %s; definedName: %s; sex: %s\n", usrInfo->registerName, usrInfo->definedName, usrInfo->sex);
}
