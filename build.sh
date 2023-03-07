#!/usr/bin/env bash

set -xe

#----------------------------
# BUILD STATIC LIBRARY
#----------------------------
# 1. Compile files for static library.
gcc -Wall -Wextra -fdiagnostics-color=always -ggdb -o clinear.o -c clinear.c
# 2. Generate static library from object file.
ar -rcs clinear.a clinear.o
# 3. Compile code that will use the library.
gcc -c main.c -Wall -Wextra -fdiagnostics-color=always -ggdb -o main.o
# 4. Link static libraries to your source object.
gcc -g -o main main.o -l:clinear.a -l:vec.a -lm -L.
# 4.1. Delete object files (optional)
# rm *.o 
# Execute program
LD_LIBRARY_PATH=. ./main