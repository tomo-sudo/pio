#pragma once

#include<mysql/mysql.h>
#include<stdbool.h>           
#include "common.h"

MYSQL *mysqlConn;


bool dbConn();
bool executeSql(const char *sqlQuery);
void printMysqlErr(const char *errInfo);
void showUserInfo(const struct userBaseInfo *usrInfo);
void queryUserNormInfoModel(char *registerName, struct userBaseInfo *sendBuf);
char* registerModel(struct userBaseInfo *recvBuf);
bool createFriendsTable(char *owner);
char* fieldValueExist(char *tableName, char *fieldName, char *fieldValue);

