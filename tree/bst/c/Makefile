CC = gcc
CFLAGS = -O2 -Wall
TARGET = main

objects = $(wildcard *.c)

$(TARGET) : $(objects)
	$(CC) $(CFLAGS) $^ -o $@ 

.PHONY : clean

clean :
	-rm $(TARGET)