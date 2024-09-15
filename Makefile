CC=gcc
CFLAGS= -Wall -Wextra -Wpedantic -std=c11
DEBUG_CFLAGS = -g -DDEBUG

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
    CFLAGS += -D_XOPEN_SOURCE=600
else
    CFLAGS += -D_POSIX_C_SOURCE=199309L
endif

test : clean test1.o test2.o test3.o ./src/faults_handle.o ./src/cust_allocation.o ./src/include/extern_memery_manager.o
	$(CC)  $(CFLAGS) ./obj/test1.o ./obj/faults_handle.o ./obj/cust_allocation.o ./obj/extern_memery_manager.o -o ./test1
	$(CC)  $(CFLAGS) ./obj/test2.o ./obj/faults_handle.o ./obj/cust_allocation.o ./obj/extern_memery_manager.o -o ./test2
	$(CC)  $(CFLAGS) ./obj/test3.o ./obj/faults_handle.o ./obj/cust_allocation.o ./obj/extern_memery_manager.o -o ./test3

test1.o : ./tests/src/test1.c
	$(CC)  $(CFLAGS) -c  ./tests/src/test1.c -o ./obj/test1.o

test2.o : ./tests/src/test2.c
	$(CC)  $(CFLAGS) -c  ./tests/src/test2.c -o ./obj/test2.o

test3.o : ./tests/src/test3.c
	$(CC)  $(CFLAGS) -c  ./tests/src/test3.c -o ./obj/test3.o

./src/faults_handle.o : ./src/faults_handle.c
	$(CC)  $(CFLAGS) -c ./src/faults_handle.c -o ./obj/faults_handle.o

./src/cust_allocation.o : ./src/cust_allocation.c
	$(CC)  $(CFLAGS) -c ./src/cust_allocation.c -o ./obj/cust_allocation.o

./src/include/extern_memery_manager.o : src/include/extern_memery_manager.c
	$(CC)  $(CFLAGS) -c ./src/include/extern_memery_manager.c -o ./obj/extern_memery_manager.o

clean:
	rm -f ./obj/*.o ./test1 ./test2 ./test3