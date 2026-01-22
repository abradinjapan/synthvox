debug:
	g++ source/main.cpp -Wextra -Wall -fsanitize=address -o ../synthvox.elf -g -lSDL3 -lGL -lGLEW -lm
