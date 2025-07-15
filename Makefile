EXECUTABLE=guard

PROJECT_FILE=main.cpp

# Compiler Options
CXX = g++
CXXFLAGS = -std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp

SOURCES     = $(wildcard *.cpp)
OBJECTS     = $(SOURCES:%.cpp=%.o)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

.PHONY: clean
clean:
	rm $(EXECUTABLE) $(OBJECTS)

all: $(EXECUTABLE)
