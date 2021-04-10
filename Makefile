CC=gcc
TARGET=ctool

all:
	$(CC) ctool.c conv.c -o $(TARGET) -lm

clean:
	rm $(TARGET)

install:
	cp $(TARGET) /usr/bin
