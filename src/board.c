#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "board.h"

void gen_random_seed() {
    // int randSeed = (time(0) * 32719 + 3) % 32749;
    int randSeed = time(0);
    srand(randSeed);
}

int gen_num(int th) {
    return rand() % (int)pow(2, th);
}

int* gen_board(int* board, int th) {
    for(int i = 0; i < th; i++)
        board[i] = gen_num(th);

    return board;
}

int validate_guess(char* guess) {

    if(strlen(guess) > 8 || strspn(guess, "01") == 0) return 0;
    return 1;
}

int check_guess(int num, int guess) {
    return (guess ^ num);
}