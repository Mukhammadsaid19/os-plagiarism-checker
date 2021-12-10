#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(EXIT_FAILURE);
}

MYSQL* mysql_connect() {
    MYSQL *connection = mysql_init(NULL);

    char *server = "localhost";
    char *user = "root";
    char *password = "22764977x7#X";
    char *database = "os_project";

    if (connection == NULL) {
        fprintf(stderr, "Could not initialize DB\n");
    }

    if (mysql_real_connect(connection, server, user, password, database, 0, NULL, 0) == NULL) {
        finish_with_error(connection);
    }

    return connection;

    // if (mysql_query(connection, "SHOW TABLES")) {
    //     fprintf(stderr, "%s\n", mysql_error(connection));
    //     mysql_close(connection);
    //     exit(EXIT_FAILURE);
    // }

    // res = mysql_use_result(connection);
	
	// printf("MySQL Tables in MySQL database:\n");
   
	// while ((row = mysql_fetch_row(res)) != NULL)
	// 	printf("%s \n", row[0]);
   
	// mysql_free_result(res);
	// mysql_close(connection);

    // exit(EXIT_SUCCESS);
}

bool login_s(MYSQL* connection, char* login, char* password) {
    MYSQL_RES *res;
    MYSQL_ROW row;
    
    char *query = (char*) malloc(256 * sizeof(char));

    // Badly prepared statement
    sprintf(query, "SELECT ID FROM user WHERE ID = '%s' AND password = '%s'", login, password);

    // Querying authentication...
    if (mysql_query(connection, query)) {
        finish_with_error(connection);
    }

    // Getting a pointer to the first matched row
    res = mysql_store_result(connection);
    int num = mysql_num_fields(res);
   
    // printf("Searching...");

	if (row = mysql_fetch_row(res)) {
        return true;
    }
    
	mysql_free_result(res);
   
    return false;
}

//mysql.c additions
void insertNewUser(MYSQL *con,  char* id,  char* firstName,  char* lastName,  char* password,  char* email)
{
    char *query = (char*) malloc(512 * sizeof(char));
    sprintf(query, "INSERT INTO user(ID, first_name, last_name, password, email) VALUES('%s', '%s', '%s', '%s', '%s')", id, firstName, lastName, password, email);
    
    
    if(mysql_query(con, query))
    {
        finish_with_error(con);
    }
}

int check_user(MYSQL *con,  char* id)
{
    char *query = (char*) malloc(128 * sizeof(char));
    sprintf(query, "SELECT ID FROM user WHERE ID='%s'", id); 
    int resultNum;
    resultNum = 0;
    if(mysql_query(con, query))
    {
         finish_with_error(con);
    }

    MYSQL_RES *result;
    result = mysql_store_result(con);
    if(result == NULL)
    {
    	mysql_free_result(result);
        finish_with_error(con);
    }
    MYSQL_ROW row;
    
    while((row = mysql_fetch_row(result)))
    {
    	resultNum = resultNum + 1;
    }
    if(resultNum == 0)
    {
    	//printf("user with id %s does not exist\n", id);
    	mysql_free_result(result);
    	return 0;
    } else if(resultNum == 1)
    {
    	//printf("user with id %s exists\n", id);
    	mysql_free_result(result);
    	return 1;
    } else {
    	printf("Something went wrong");
    	mysql_free_result(result);
    	mysql_close(con);
    	exit(1);
    }
}

bool signup_s(MYSQL *con,  char* id,  char* firstName,  char* lastName,  char* password,  char* email)
{
    if(check_user(con, id))
    {
        //printf("User with id %s is not inserted because he alread exists in database\n", id);
        return false;
    } else
    {
    	//printf("User with id %s is inserted\n", name);
    	insertNewUser(con, id, firstName, lastName, password, email);
    	return true;
    }
    
}