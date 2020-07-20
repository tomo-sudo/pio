#include "server.h"

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










