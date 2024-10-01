CC=gcc
CFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c11 -static -g
DEBUG_CFLAGS = -g -DDEBUG

LIB_NAME = libcust_allocation.a

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
    CFLAGS += -D_XOPEN_SOURCE=600
else
    CFLAGS += -D_POSIX_C_SOURCE=199309L
endif


SRCS = ./src/cust_allocation.c ./src/faults_handle.c ./src/include/extern_memery_manager.c
HDRS = ./src/include/cust_allocation.h ./src/include/faults_handle.h

all : clean $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rcs $(LIB_NAME) *.o
	rm -f *.o

test : clean test1.o test2.o test3.o ./src/faults_handle.o ./src/cust_allocation.o ./src/include/extern_memery_manager.o
	$(CC)  $(CFLAGS) ./obj/test1.o ./obj/faults_handle.o ./obj/cust_allocation.o ./obj/extern_memery_manager.o -o ./test1
	#$(CC)  $(CFLAGS) ./obj/test2.o ./obj/faults_handle.o ./obj/cust_allocation.o ./obj/extern_memery_manager.o -o ./test2
	#$(CC)  $(CFLAGS) ./obj/test3.o ./obj/faults_handle.o ./obj/cust_allocation.o ./obj/extern_memery_manager.o -o ./test3

clean:
	rm -f *.o $(LIB_NAME)


clean:
	rm -f ./obj/*.o ./test1 ./test2 ./test3 $(LIB_NAME)
