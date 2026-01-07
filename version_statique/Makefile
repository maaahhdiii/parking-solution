CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -lm
TARGET = parking_statique
SOURCES = main.c parking.c vehicule.c statistic.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c parking.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean

