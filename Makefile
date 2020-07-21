LIBS     := -lsfml-graphics -lsfml-window -lsfml-system -lpthread
CXX      := -g++
CXXFLAGS := -std=c++11 -g3
BUILD    := ./build
OBJ_DIR  := obj
APP_DIR  := bin
TARGET   := program
INCLUDE  := -I include/
SRC      :=                                                 \
	$(wildcard src/managed/*.cpp)                           \
	$(wildcard src/rendering/*.cpp)                         \
	$(wildcard src/scenes/*.cpp)                            \
	$(wildcard src/scenes/WorldScene/*.cpp)                 \
	$(wildcard src/scenes/WorldScene/units/*.cpp)           \
	$(wildcard src/scenes/WorldScene/units/buildings/*.cpp) \
	$(wildcard src/*.cpp)                                   \

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ $(LIBS)

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LIBS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
