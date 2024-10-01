CC=gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -g
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
OBJ_DIR = ./obj


all : clean $(SRCS) $(HDRS)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRCS)
	mv *.o $(OBJ_DIR)
	ar rcs $(LIB_NAME) $(OBJ_DIR)/*.o
	#rm -f $(OBJ_DIR)*.o

OBJ_DIR_TESTS = ./tests/outs

LDFLAGS = -L. -lcust_allocation

test : test_clean obj_dir $(foreach test, $(wildcard tests/src/test*.c), $(test:.c=))
	$(CC) $(CFLAGS) $(LDFLAGS) $(foreach test, $(wildcard tests/src/test*.c), $(patsubst %.c,%.o, $(test))) -o $(@:test=%)
	rm -rf tests/src/*.dSYM
	mkdir tmp
	mv tests/src/*.c /tmp
	mv * tests/outs
	mv tmp/* tests/src/




#test: test_clean obj_dir $(foreach test, $(wildcard tests/src/test*.c), $(test:.c=.o))
#	$(CC) $(CFLAGS) $(LDFLAGS) $(foreach test, $(wildcard $(OBJ_DIR_TESTS)/test*.o), $(test)) -o $(OBJ_DIR_TESTS)/$(@:test=%)


obj_dir :
	mkdir -p $(OBJ_DIR_TESTS)

test_clean:
	rm -rf ./*.o ./obj/*.o ./tests/src/test1 ./tests/src/test2 ./tests/src/test3 ./tests/src/*.dSYM ./tests/src/*.o


clean:
	rm -rf ./*.o ./obj/*.o ./tests/src/*.o ./tests/src/test1 ./tests/src/test2 ./tests/src/test3 ./tests/src/*.dSYM $(LIB_NAME)


