OBJS = $(wildcard src/*.c)
CC = gcc

INCLUDE_PATHS = -Iinclude
LIBRARY_PATHS = -Llib

COMPILER_FLAGS = -g
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2_image -lSDL2 -lm
PROGRAM_NAME = citrus.exe
DEBUG_PATH = bin/debug/

all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o ./$(DEBUG_PATH)$(PROGRAM_NAME)

run: ./$(DEBUG_PATH)$(PROGRAM_NAME)
	./$(DEBUG_PATH)$(PROGRAM_NAME)