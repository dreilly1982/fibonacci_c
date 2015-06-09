CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.c bigint.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=fibonacci

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
