#include "userInfo.h"

int main(int argc, char *argv[])
{

	void printMysqlErr(const char *);	
	void queryUserNormInfoModel(char *registerName, struct userBaseInfo *sendBuf);
	char* registerModel(struct userBaseInfo *recvBuf);
	bool dbConn();

	bool connState = dbConn();
	if(!connState)
	{
		printMysqlErr("conn failed");	
		return -1;
	}

       	struct userBaseInfo sendBuf;
       	struct userBaseInfo recvBuf;
	strncpy(recvBuf.registerName, "wang", 5);
	strncpy(recvBuf.definedName, "kuw", 4);
	strncpy(recvBuf.sex, "男", strlen("男") + 1);
	strncpy(recvBuf.password, "123", 4);

	queryUserNormInfoModel("zhang", &sendBuf);
	registerModel(&recvBuf);



//	void serverSock();
//	serverSock();

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

char* registerModel(struct userBaseInfo *recvBuf)
{
	if(!(recvBuf->registerName && recvBuf->definedName && recvBuf->sex && recvBuf->password))
		return "1";

	bool executeSql(const char *);
	bool createFriendsTable(char *owner);

	char* fieldValueExist(char *tableName, char *fieldName, char *fieldValue);


	char queryTemp[500];            //must make sure size of queryTemp array is enough
	memset(queryTemp, 0, sizeof(queryTemp));
	sprintf(queryTemp, "insert into userBaseInfo(registerName,definedName,sex,password)values(\'%s\',\'%s\',\'%s\',\'%s\');", recvBuf->registerName, recvBuf->definedName, recvBuf->sex, recvBuf->password);	
	//printf("%s\n", queryTemp);

	char* fVRt;
	if(strncmp((fVRt = fieldValueExist("userBaseInfo", "registerName", recvBuf->registerName)), "1", 1) == 0)
		return "2";


	if(executeSql(queryTemp) == false)                             //if data reassigned to field in primary key, executeSql will return false
		return "3";
	else
	{
		memset(queryTemp, 0, sizeof(50));
		sprintf(queryTemp, "mkdir  -m 777 /home/gxr/userFiles/%s", recvBuf->registerName);
	//	printf("%s\n", queryTemp);
		system(queryTemp);
		createFriendsTable(recvBuf->registerName);

		return "4";
	}

}

bool createFriendsTable(char *owner)
{
	bool executeSql(const char *);

	char queryTemp[110];   //const decorating data can be converted to array but char * type pointer
	sprintf(queryTemp, "create table %s(registerName varchar(20) primary key, msgFileName varchar(20) not null);", owner);
	if(executeSql(queryTemp))
		return true;
	else
		return false;
        
}

char* fieldValueExist(char *tableName, char *fieldName, char *fieldValue)
{
	if(!(tableName && fieldName && fieldValue))
		return "3";


	char tmp[120], value[120];
	memset(tmp, 0, sizeof(tmp));
	memset(value, 0, sizeof(value));
	bool executeSql(const char *);
		
	sprintf(tmp, "select * from %s where %s=\'%s\';", tableName, fieldName, fieldValue);
//	printf("%s\n", tmp);

	if(executeSql(tmp) == false) //only when no this table will select failed, even select result is 0 rows, only table exists, select successfully 
	{
		printf("");
		return "4";
	}


	MYSQL_RES *resultSet = mysql_store_result(mysqlConn);
     	int rows = mysql_num_rows(resultSet);
        mysql_free_result(resultSet);
	if(rows == 0)
	{
		printf("No user %s\n", fieldValue);
		return "0";
	}
		return "1";
}

