#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

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
        fprintf(stderr, "%s\n", mysql_error(connection));
        mysql_close(connection);
        exit(EXIT_FAILURE);
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
    
    char *query = (char*) malloc(255 * sizeof(char));

    // Badly prepared statement
    sprintf(query, "SELECT login FROM user WHERE login = '%s' AND password = '%s'", login, password);

    // Querying authentication...
    if (mysql_query(connection, query)) {
        fprintf(stderr, "%s\n", mysql_error(connection));
        mysql_close(connection);
        exit(EXIT_FAILURE);
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

// void sign_up(MYSQL* connection, struct login_data);

// int main() {
//     MYSQL *conn = mysql_connect();

//     login(conn, "saidov", "sosecure");
//     return 0;
// }