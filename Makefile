# C++ Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = src
BIN_DIR = bin
LIB_DIR = lib
EXEC = $(BIN_DIR)/pong

# Libraries
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Sources
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Default target
all: $(EXEC)

# Link the executable
$(EXEC): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) -o $@ $(OBJECTS) -L$(LIB_DIR) $(LIBS)

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ_DIR)/*.o $(EXEC)
