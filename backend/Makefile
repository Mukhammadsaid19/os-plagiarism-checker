CC = gcc

CPPFLAGS += -I/usr/include/mysql

LDLIBS += -lmysqlclient -lpthread


server: server.c mysql.c
	$(CC) $(CFLAGS) -o server server.c mysql.c $(LDLIBS)


.PHONY: clean

clean:
	rm *.o output
