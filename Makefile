# Makefile

CXX = g++
CXXFLAGS = -Wall -g
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
SRC = main.cpp Game.cpp Entity.cpp Mobility.cpp Player.cpp Ball.cpp Menu.cpp AI.cpp KeyBoard.cpp PowerUp.cpp Wall.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = sfml_game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $(TARGET) $(OBJ) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)

run: ./sfml_game

.PHONY: clean
