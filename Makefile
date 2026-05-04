CXX = g++
CXXFLAGS = -O2 -std=c++17

SRC = src/main.cpp src/standard.cpp src/strassen.cpp src/matrix_utils.cpp
OBJ = $(SRC:.cpp=.o)

main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o main $(OBJ)

clean:
	rm -f main src/*.o
