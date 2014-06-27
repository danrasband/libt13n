# Makefile for libt13n and transliterate

SHELL = /bin/sh
CC    = gcc
PREFIX?=$(DESTDIR)/usr/local
BINDIR?=$(PREFIX)/bin

PROGRAM_NAME   	= transliterate
PROGRAM_OBJECTS = transliterate.o
LIBT13N_TARGET  = libt13n.so
LIBT13N_OBJECTS = t13n.o

CFLAGS  = -Wall -Wextra
LDFLAGS = -shared

all: $(PROGRAM_NAME)
	@echo ""
	@echo "Compiled all."
	@echo ""

.PHONY: all

$(PROGRAM_NAME): $(LIBT13N_TARGET)
	$(CC) $(CFLAGS) -o $(PROGRAM_NAME) $(PROGRAM_OBJECTS)

$(LIBT13N_TARGET): $(LIBT13N_OBJECTS) $(PROGRAM_OBJECTS)
	$(CC) $(CFLAGS) -o $(LIBT13N_TARGET) $(PROGRAM_OBJECTS) $(LDFLAGS)

%.o: %.c
	$(CC) -c $<

clean:
	rm $(PROGRAM_NAME) $(LIBT13N_TARGET) *.o

.PHONY: clean
