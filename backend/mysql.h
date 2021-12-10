#ifndef MYSQL_H
#define MYSQL_H
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

MYSQL* mysql_connect();
void finish_with_error(MYSQL *con);
bool login_s(MYSQL* connection, char* login, char* password);
int check_user(MYSQL *con,  char* id);
void insertNewUser(MYSQL *con,  char* id,  char* firstName,  char* lastName,  char* password,  char* email);
bool signup_s(MYSQL *con,  char* id,  char* firstName,  char* lastName,  char* password,  char* email);

#endif