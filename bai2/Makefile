CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = filestat
SRC = filestat.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
