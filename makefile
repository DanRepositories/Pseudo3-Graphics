OBJS = main.cpp

CC = g++

COMP_FLAGS = -w

LINKER_FLAGS = -lSDL2

EXE_NAME = executable

all: $(OBJS)
	$(CC) $(OBJS) $(COMP_FLAGS) $(LINKER_FLAGS) -o $(EXE_NAME)
