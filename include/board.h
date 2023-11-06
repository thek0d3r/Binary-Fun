#ifndef BOARD_H
#define BOARD_H

#include <time.h>

void gen_random_seed();
int gen_num(int th);
int* gen_board(int* board, int th);
int validate_guess(char* guess);
int check_guess(int num, int guess);

extern int th;
extern int* board;

#endif // BOARD_H