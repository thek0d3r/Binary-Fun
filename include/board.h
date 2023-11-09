#ifndef BOARD_H
#define BOARD_H

#include <time.h>

void gen_random_seed();
void gen_board(int **board, int *nums, int th);
int gen_num(int th);
int check_binarity(int **guess, int th);
int check_row(int **guess, int **board, int th, int rand);

#endif // BOARD_H