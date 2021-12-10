SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := ./bin
# SDL_DIR := C:/SDL2

EXE := $(BIN_DIR)/main.exe
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CXX      := g++
CPPFLAGS := -I inc #-MMD -MP -I $(SDL_DIR)/include/SDL2
CXXFLAGS := -Wall -Wextra -std=c++17 -ggdb
LDFLAGS  := -Llib #-L $(SDL_DIR)/lib
LDLIBS   := -lmingw32 # -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_ttf

.PHONY: all clean run

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

run:
	$(EXE)

-include $(OBJ:.o=.d)