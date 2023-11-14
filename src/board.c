#include <stdlib.h>
#include <stdio.h>
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
    return 1 + rand() % ((int)pow(2, th) - 1);
}

void gen_board(int **board, int *nums, int th) {
    for(int i = 0; i < th; i++) {
        int num = gen_num(th);

        *(nums+i) = num;

        for(int k = i - 1; k >= 0; k--) {
            if(*(nums+k) == num) {
                while(*(nums+k) == num) num = gen_num(th);
                *(nums+i) = num;
            }
        }

        for (int j = th - 1; j >= 0; j--) {
            *(*(board + i) + j) = ((num >> (th - j - 1)) & 1);
        }

    }

}


int check_binarity(int **guess, int th) {
    for(int i = 0; i < th; i++) 
        for(int j = 0; j < th; j++)
            if(*(*(guess+i)+j) != 0 && *(*(guess+i)+j) != 1) {
                *(*(guess+i)+j) = 0;
                return 0;
            }

    return 1;
}

int check_row(int **guess, int **board, int th, int rand) {
    for(int j = 0; j < th; j++){
        if(*(*(guess+rand)+j) != *(*(board+rand)+j)) {
            *(guess+rand) = (int*)calloc(th, sizeof(int));
            return 0;
        }

    }

    return 1;
}