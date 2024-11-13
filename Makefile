SRC= $(wildcard src/*.c)
CC= gcc
CFLAGS= -Wall -Wextra -Werror -g -pedantic -Wshadow
OPTS= -O0
INCLUDES= -I./include/
LIBS= -lraylib -lm
TARGET= reflex.o

all:
	$(CC) $(CFLAGS) $(OPTS) $(INCLUDES) -o $(TARGET) $(SRC) $(LIBS)

run:
	./$(TARGET)
