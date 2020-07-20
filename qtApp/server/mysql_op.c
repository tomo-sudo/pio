#include "mysql_op.h"

bool dbConn()
{
	const char *hostName = NULL;  
	const char *userName = "root";
	const char *passWd = "123456";
	const char *dbName = "userInfo";
	const char *unixSocket = NULL;   
	const unsigned int dbPort = 0;  
	const int clientFlag = 0;   


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
