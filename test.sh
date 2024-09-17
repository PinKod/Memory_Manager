#!/bin/bash



make test



valgrind --tool=memcheck --leak-check=yes --leak-check=full ./test1
valgrind --tool=memcheck --leak-check=yes --leak-check=full ./test2
valgrind --tool=memcheck --leak-check=yes --leak-check=full ./test3

