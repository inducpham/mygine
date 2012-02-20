CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lcurses -lpanel
SOURCES=main.cpp GameLoop.cpp SimpleModule.cpp AbstractModule.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=mygine

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o mygine
