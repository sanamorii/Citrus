OBJS = $(wildcard src/*.cpp)
CC = g++

INCLUDE_PATHS = -Iinclude -IC:\dev\msys2\mingw64\include\SDL2
LIBRARY_PATHS = -Llib -LC:\dev\msys2\mingw64\lib

COMPILER_FLAGS = -g
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2_image -lSDL2 -lm
PROGRAM_NAME = citrus.exe
OUTPUT_PATH = bin/

all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o ./$(OUTPUT_PATH)$(PROGRAM_NAME)

run: ./$(DEBUG_PATH)$(PROGRAM_NAME)
	./$(DEBUG_PATH)$(PROGRAM_NAME)