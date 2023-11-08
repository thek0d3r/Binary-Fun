build:
	gcc -O3 src/main.c src/board.c -I include -o out/binfun -lm