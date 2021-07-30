SRC_FOLDER = src

OBJS = main.cpp

CC = g++

COMP_FLAGS = -w

LINKER_FLAGS = -lSDL2

EXE_NAME = output/executable

all: $(SRC_FOLDER)/$(OBJS)
	$(CC) $^ $(COMP_FLAGS) $(LINKER_FLAGS) -o $(EXE_NAME)
