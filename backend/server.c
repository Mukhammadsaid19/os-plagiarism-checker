/* server.c */

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h> // socket address
#include <string.h>
#include <pthread.h>
#include "mysql.h"

#define PORT 8080
#define MAX 512

char* _login(char*, char*);
char* router(char*);
void *process(void *ptr);

// Socket structure
typedef struct
{
    int sock;
    struct sockaddr address;
    int addr_len;
} connection_t;

void closeSocket(int sock)
{
    close(sock);
    return;
}

int main(int argc, char **argv)
{
    int sock = -1;
    struct sockaddr_in address;
    int port = PORT;
    connection_t *connection;
    pthread_t thread;

    /* create socket */
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock <= 0)
    {
        fprintf(stderr, "%s: error: cannot create socket\n", argv[0]);
        return -3;
    }

    /* bind socket to port */
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(sock, (struct sockaddr *)&address, sizeof(struct sockaddr_in)) < 0)
    {
        fprintf(stderr, "error: cannot bind socket to port %d\n", port);
        return -4;
    }

    /* listen on port */
    if (listen(sock, 5) < 0)
    {
        fprintf(stderr, "error: cannot listen on port\n");
        return -5;
    }

    printf("ready and listening\n");

    while (1)
    {
        /* accept incoming connections */
        connection = (connection_t *)malloc(sizeof(connection_t));
        connection->sock = accept(sock, &connection->address, &connection->addr_len);
        if (connection->sock <= 0)
        {
            free(connection);
        }
        else
        {
            /* start a new thread but do not wait for it */
            pthread_create(&thread, 0, process, (void *)connection);
            pthread_detach(thread);
        }
    }

    return 0;
}

void *process(void *ptr)
{
    char* buff;
    int nread;

    connection_t *conn;
    long addr = 0;

    if (!ptr)
        pthread_exit(0);
    conn = (connection_t *) ptr;

    /* Set up buffer */
    buff = (char *)malloc((MAX)*sizeof(char));
	buff[MAX - 1] = 0;

    /* Reading from the client */
    while ((nread = read(conn->sock, buff, MAX)) > 0)
    {
        addr = (long)((struct sockaddr_in *)&conn->address)->sin_addr.s_addr;
        printf("%d.%d.%d.%d: %s\n",
               (int)((addr)&0xff),
               (int)((addr >> 8) & 0xff),
               (int)((addr >> 16) & 0xff),
               (int)((addr >> 24) & 0xff),
               buff);

        // printf("\nReceived %d bytes\n", nread);

        // printf("From client: %s\n", buff);


        // Delegate request to the router
        char* res = router(buff);

        // Sending the response...
        send(conn->sock, res, 48, 0);

    }

    printf("Closing connection to client\n");
    printf("----------------------------\n");

    /* close socket and clean up */
    free(buff);
    close(conn->sock);
    free(conn);
    pthread_exit(0);
}


char* router(char* request) {
    char delim[] = " ";
    char* route = strtok(request, delim);

    printf("ROUTER: %s\n", route);

    if (strcmp(route, "login") == 0) {
        // Data in the format "route login password"
        route = strtok(NULL, delim);
        char* login = route;

        route = strtok(NULL, delim);
        char* password = route;

        // Printing data
        printf("LOGIN: %s %s\n", login, password);

        return _login(login, password);

    } else if (strcmp(route, "register") == 0) {

    } else {

    }

    return "";
}

/*
    Checks the credentials and returns result
*/
char* _login(char* login, char* password) {
    // Initialize the database connection
    MYSQL* conn = mysql_connect();
    bool result = login_s(conn, login, password);

    return result ? "login 201" : "login 403";
}

// TODO: Make registation endpoint

// TODO: Make plagiarism check endpoint