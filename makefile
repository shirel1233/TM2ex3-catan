# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -I.

# Sources and headers
SOURCES = Demo.cpp board.cpp building.cpp catan.cpp city.cpp DevelopmentCard.cpp hexagon.cpp player.cpp resource.cpp RoadSegment.cpp segment.cpp test.cpp
HEADERS = board.hpp building.hpp catan.hpp city.hpp DevelopmentCard.hpp hexagon.hpp player.hpp resource.hpp RoadSegment.hpp segment.hpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable names
TARGETS = demo test

# Default target
all: $(TARGETS)

# Link the object files to create the executable for demo
demo: $(OBJECTS)
	$(CXX) $(CXXFLAGS) Demo.o board.o building.o catan.o city.o DevelopmentCard.o hexagon.o player.o resource.o RoadSegment.o segment.o -o demo

# Link the object files to create the executable for test
test: $(OBJECTS)
	$(CXX) $(CXXFLAGS) test.o board.o building.o catan.o city.o DevelopmentCard.o hexagon.o player.o resource.o RoadSegment.o segment.o -o test

# Compile each source file into an object file
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(TARGETS) $(OBJECTS)

# Run the main program
run_demo: demo
	./demo

# Run the tests
run_test: test
	./test

# Rebuild the project
rebuild: clean all

.PHONY: all clean run_demo run_test rebuild
