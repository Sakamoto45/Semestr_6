CC=g++
CFLAGS=-c -g
LDFLAGS=
SOURCES=string_swap.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=exe

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ && rm -rf *.o

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o