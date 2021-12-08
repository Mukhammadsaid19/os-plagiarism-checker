#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h> // socket address
#include <string.h>
#include "mysql.h"

#define PORT 8080
#define MAX 1024

char* api(char*);
char* login(char*);
char* router(char*, char*);

int main(int argc, char const *argv[]) {

    int server_fd;
    int backlog = 30;
    struct sockaddr_in address;

    int new_socket, valread;

    int opt = 1;
    int addrlen = sizeof(address);


    // Creating a server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    printf("Creating a server socket...\n");
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket creation is failed.");
        exit(EXIT_FAILURE);
    }

    printf("Defining the server socket options, family, adress & port. \n");
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed.");
        exit(EXIT_FAILURE);
    }

    printf("Binding the server socket to port 8080...\n");
    if (bind(server_fd, (struct sockaddr*) &address, sizeof(address)) < 0) {
        perror("Socket bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Server starts to listen...\n");
    if (listen(server_fd, backlog) < 0) {
        perror("Socket listen failed ");
        exit(EXIT_FAILURE);
    } 
    // for ( ; ; ) {
        // fflush(stdout);

        printf("New listening...");

        // Server accepts clients

        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Socket accept failed");
            exit(EXIT_FAILURE);
        }
        printf("New client arrived...");

        char buffer[1024]; // Buffer to read from the client
        memset(buffer, 0, 1024);
        read(new_socket, buffer, 1023);

        // char str[] = "login saidov sosecure";
        // char* response = api(str);

        char* response = api(buffer);

        // char* stub = "HTTP/1.0 200 OK\r\n\r\nHello"; // Stub response

        printf("%s\n", buffer);

        printf("Reading done...");

        send(new_socket, response, strlen(response), 0);

        fflush(stdout);

        // write(new_socket, (char*) buffer, strlen((char*) buffer));
        close(new_socket);
    // }

    return 0;
}

char* router(char* route, char* request) {
    if (strcmp(route, "login") == 0) {
        return login(request);
    } else if (strcmp(route, "register") == 0) {

    } else {

    }

    return "";
}

char* api(char* request) {
    char delim[] = " ";
    char req[128] = "";

    strcpy(req, request);

    char* api = strtok(request, delim);

    return router(api, req);
}

char* login(char* request) {
    // Receives data in the format "login email password"
    char delim[] = " ";

    char* ptr = strtok(request, delim);
    char* api = ptr;

    ptr = strtok(NULL, delim);
    char* email = ptr;

    ptr = strtok(NULL, delim);
    char* password = ptr;

    // printf("login: %s, %s", email, password);

    // Initialize the database connection
    MYSQL* conn = mysql_connect();
    bool result = login_s(conn, email, password);

    return result ? "201" : "403";
}

// void chat(int sockd) {
//     char buff[MAX];
//     char schat[MAX];
//     // char* response = "200 OK";
//     char* bye = "Bye";

//     while(1) {
//         // Reading from Server
//         memset(buff, 0, sizeof(buff));
//         read(sockd, buff, MAX);
//         printf("%s\n", buff);

//         // // Getting message from terminal
//         // memset(schat, 0, sizeof(schat));
//         // printf("SERVER: ");
//         // fgets(schat, sizeof(schat), stdin);
//         // send(sockd, schat, strlen(schat), 0);
//         // schat[strlen(schat)] = '\0';

//         // // Checking if it was a terminal signal
//         // if(strncmp(schat, bye, strlen(bye)) == 0) {
//         //     break;
//         // }
//     }
// }