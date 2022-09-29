#!/bin/bash

gcc -Wall -g -o "$1" "$1.c" "main.c"
g++ -Wall -g -o "$1_test" "$1.c" "$1_test.cpp" -lgtest -pthread -std=c++0x

valgrind --leak-check=full "./$1" < ./sample_input.txt
valgrind --leak-check=full "./$1_test"
./"$1_test"
