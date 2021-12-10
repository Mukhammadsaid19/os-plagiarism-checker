CC = gcc

PY_CFLAGS  := $(shell python3-config --cflags --embed)
PY_LDFLAGS := $(shell python3-config --ldflags --embed)

CPPFLAGS += -I/usr/include/mysql -I/usr/include/python3.8 
LDLIBS += -lmysqlclient -lpthread


server: server.c mysql.c
	$(CC) $(PY_CFLAGS) -fpie $(CPPFLAGS) -o server server.c mysql.c $(LDLIBS) $(PY_LDFLAGS)

test: test.c
	$(CC) -fpie $(python3-config --cflags --embed) 'test.c' $(python3-config --embed --ldflags)

.PHONY: clean

clean:
	rm *.o output
