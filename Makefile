CC = gcc
CFLAGS = -Wall -fPIC
OBJ = bsysutils.o

# Targets
all: static shared

# Static Library
static: libstrutils.a main_static

libstrutils.a: $(OBJ)
	ar rcs $@ $^

main_static: main.c libstrutils.a
	$(CC) main.c -L. -lstrutils -o main_static

# Shared Library
shared: libstrutils.so main_shared

libstrutils.so: $(OBJ)
	$(CC) -shared -o $@ $^

main_shared: main.c libstrutils.so
	$(CC) main.c -L. -lstrutils -o main_shared

# Clean
clean:
	rm -f *.o *.a *.so main_static main_shared
