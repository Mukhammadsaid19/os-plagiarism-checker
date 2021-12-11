/* server.c */

#include <stdio.h>
#include <Python.h>
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
#define MAX 4096

char* _plagiarism_checker(char*, char*);
char* _login(char*, char*);
char* _signup(char*, char*, char*, char*, char*);
char* router(char*);
void *process(void *ptr);
double plag_check(char*, char*);
void save_as_files(char*, char*);

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
    // char* res = _signup("U1910222", "usersaid", "Saidakbar", "Saidakhmedov", "sosecure", "s.saidov@gmail.com");

    // printf("RES: %s", res);
    // _plagiarism_checker("We are here", "You are there");
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

    printf("Ready and listening...\n");

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
            pthread_create(&thread, 0, process, (void *) connection);
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
    struct sockaddr_in* addr;
    char ip[INET_ADDRSTRLEN];
    int port;

    if (!ptr)
        pthread_exit(0);
    conn = (connection_t *) ptr;

    /* Set up buffer */
    buff = (char *)malloc((MAX)*sizeof(char));
	buff[MAX - 1] = 0;


    /* Reading from the client */
    while ((nread = read(conn->sock, buff, MAX)) > 0)
    {
        addr = (struct sockaddr_in *) &conn->address;
        port = addr->sin_port;
        
        inet_ntop(AF_INET, &(addr->sin_addr), ip, INET_ADDRSTRLEN);

        printf("%s:%d\t%s\n", ip, port, buff);

        // Delegate request to the router
        char* res = router(buff);

        // Sending the response...
        bzero(buff, MAX);

        send(conn->sock, res, 48, 0);

    }

    printf("Closing connection with the client at %s:%d\n", ip, port);
    // printf("----------------------------\n");

    /* close socket and clean up */
    free(buff);
    close(conn->sock);
    free(conn);
    pthread_exit(0);
}


char* router(char* request) {
    char delim[] = " ";
    char* route = strtok(request, delim);

    // printf("ROUTER: %s\n", route);

    if (strcmp(route, "login") == 0) {
        // Data in the format "route login password"
        route = strtok(NULL, delim);
        char* login = route;

        route = strtok(NULL, delim);
        char* password = route;

        // Printing data
        // printf("LOGIN: %s %s\n", login, password);

        return _login(login, password);

    } else if (strcmp(route, "signup") == 0) {
        // Data in the format "signup <id> <login> <fn> <ln> <pass> <email>"
        route = strtok(NULL, delim);
        char args[5][512];
        int i = 0;
        while(route != NULL) {
            strcpy(args[i], route);
            route = strtok(NULL, delim);
            i++;
        }

        // printf("SIGNUP: %s %s %s %s %s %s\n", args[0], args[1], args[2], args[3], args[4], args[5]);
        return _signup(args[0], args[1], args[2], args[3], args[4]);

    } else if (strcmp(route, "check") == 0) {
        // Data in the format "check <string1> <string2>"
        route = strtok(NULL, "<<<");
        char* text1 = route;

        route = strtok(NULL, "<<<");
        char* text2 = route;

        // printf("%s:%s\n", text1, text2);

        return _plagiarism_checker(text1, text2);
        
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

/*
    Signs up new user
*/
char* _signup(char* id, char* firstName, char* lastName, char* password, char* email)
{
    MYSQL* con = mysql_connect();
    bool result = signup_s(con, id, firstName, lastName, password, email);
    return result ? "signup 201" : "signup 500";
}

/*
    Checks the similarity between two strings.
*/
char* _plagiarism_checker(char* string1, char* string2) {
    save_as_files(string1, string2);

    // printf("SAVED FILES\n");

    double sim = plag_check("file1", "file2");

    char *res = (char*) malloc(16 * sizeof(char));

    sprintf(res, "check %.2f\n", sim);

    // printf("RES: %s\n", res);

    return res;
}

/* 
    Saves two strings as two files using File Management
*/
void save_as_files(char* string1, char* string2) {
    // Creting two files
    FILE *fp1 = fopen("file1", "w");
    FILE *fp2 = fopen("file2", "w");

    if (fp1 != NULL  && fp2 != NULL) {
        // Writing data
        fputs(string1, fp1);
        fputs(string2, fp2);

        // Closing the files
        fclose(fp1);
        fclose(fp2);
    }
}


/*
    Checks the similarity between two files
*/
double plag_check(char* file1, char* file2) {
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    int i;
	const char* module_name = "main";
	const char* func_name = "compare";

    Py_Initialize();
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('.')");
	PyRun_SimpleString("sys.path.append('../logic')");
    pName = PyUnicode_DecodeFSDefault(module_name);

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, func_name);
        /* pFunc is a new reference */

        if (pFunc && PyCallable_Check(pFunc)) {
			int arg_count = 2;
			const char *args[2];
			args[0] = file1;
			args[1] = file2;
            pArgs = PyTuple_New(arg_count);
            for (i = 0; i < arg_count; ++i) {
				pValue = PyUnicode_DecodeFSDefault(args[i]);
                // pValue = PyLong_FromLong(atoi(args[i]));
                if (!pValue) {
                    Py_DECREF(pArgs);
                    Py_DECREF(pModule);
                    fprintf(stderr, "Cannot convert argument\n");
                    return 1;
                }
                /* pValue reference stolen here: */
                PyTuple_SetItem(pArgs, i, pValue);
            }
            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                // printf("Result of call: %f\n", PyFloat_AsDouble(pValue));
                double res = PyFloat_AsDouble(pValue);
                Py_DECREF(pValue);
                return res;
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return 1;
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"%s\"\n", func_name);
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", func_name);
        return 1;
    }
    if (Py_FinalizeEx() < 0) {
        return 120;
    }
    return 0;
}