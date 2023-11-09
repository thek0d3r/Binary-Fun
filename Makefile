build:
	gcc -O3 src/main.c src/board.c src/screen.c -I include -o out/binfun -lm