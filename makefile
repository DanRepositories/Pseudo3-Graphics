# Compilador a usar
CC = g++

# Opciones de compilacion
C_FLAGS = -w

# Librerias a enlazar
LINKER_FLAGS = -lSDL2

# Rutas de directorios
DIR_SOURCE = src
DIR_OBJS = bin

# Nombre del ejecutable
EXE_NAME = output/executable

# Ficheros objeto utilizados
OBJS_FILES = $(DIR_SOURCE)/main.cpp

## Reglas de compilacion
all: $(OBJS_FILES)
	$(CC) $^ $(COMP_FLAGS) $(LINKER_FLAGS) -o $(EXE_NAME)

clean:
	$(RM) $(DIR_OBJS)/*.o $(EXE_NAME) core

