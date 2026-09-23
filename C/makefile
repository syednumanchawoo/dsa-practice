# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Automatically find ALL .c files inside the lib/ directory
LIB_SRC = $(wildcard lib/*.c)

# Pattern rule to compile and automatically execute any .c file
%: %.c $(LIB_SRC)
	$(CC) $(CFLAGS) $@.c $(LIB_SRC) -o $@.exe
	.\$@.exe

# Delete all compiled executables recursively
clean:
	del /S /Q *.exe


