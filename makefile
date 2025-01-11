# Makefile
CXX = g++ # Ye hamara compiler hota hai
CXXFLAGS = -Wall -pthread # uh Wall hamne use kiya to see any compiler warnings.

TARGET = main
SRC = main.cpp map_operations.cpp split_sentence.cpp shuffle.cpp reduce.cpp globals.cpp
OBJ = main.o map_operations.o split_sentence.o shuffle.o reduce.o globals.o

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)
