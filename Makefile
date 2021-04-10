CC=gcc
TARGET=ctool

# define the path
ifeq ($(shell uname), Linux)
	INSTALL_PATH += /usr/bin
else ifeq ($(shell uname), Darwin)
	INSTALL_PATH += /usr/local/bin
endif

all:
	$(CC) ctool.c conv.c -o $(TARGET) -lm

clean:
	rm $(TARGET)

install:
	cp $(TARGET) $(INSTALL_PATH)
