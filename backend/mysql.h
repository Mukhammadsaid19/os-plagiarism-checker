#ifndef MYSQL_H
#define MYSQL_H
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

MYSQL* mysql_connect();
bool login_s(MYSQL* connection, char* login, char* password);

#endif