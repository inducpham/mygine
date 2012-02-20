CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lcurses -lpanel
SOURCES=main.cpp ../GameLoop.cpp ../AbstractModule.cpp ../LabelComponent.cpp ../AbstractComponent.cpp PalleteModule.cpp PaintHost.cpp StartModule.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ncpaint

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(EXECUTABLE)
