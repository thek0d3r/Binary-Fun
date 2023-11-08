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
    return rand() % (int)pow(2, th);
}

void gen_board(int **board, int *nums, int th) {
    for(int i = 0; i < th; i++) {
        for(int j = 0; j < th; j++) {
            int num = gen_num(th);

            nums[i] = num;

            for(int k = th-1; k >= 0; k--) {
                board[i][j] = ((num>>k) & 1);
                j++;
            }

            j--;
        }
    }
}

void print_screen(int **board, int *nums, int th) {
    print_banner();

    for(int i = 0; i < th; i++) {
        printf("%4d  ", nums[i]);
        for(int j = 0; j < th; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

void print_banner() {
    printf("\n");
    printf(" /$$$$$$$  /$$                                               /$$$$$$$$                 \n");
    printf("| $$__  $$|__/                                              | $$_____/                 \n");
    printf("| $$  \\ $$ /$$ /$$$$$$$   /$$$$$$   /$$$$$$  /$$   /$$      | $$    /$$   /$$ /$$$$$$$ \n");
    printf("| $$$$$$$ | $$| $$__  $$ |____  $$ /$$__  $$| $$  | $$      | $$$$$| $$  | $$| $$__  $$\n");
    printf("| $$__  $$| $$| $$  \\ $$  /$$$$$$$| $$  \\__/| $$  | $$      | $$__/| $$  | $$| $$  \\ $$\n");
    printf("| $$  \\ $$| $$| $$  \\ $$ /$$__  $$| $$      | $$  | $$      | $$   | $$  | $$| $$  | $$\n");
    printf("| $$$$$$$/| $$| $$  \\ $$|  $$$$$$$| $$      |  $$$$$$$      | $$   |  $$$$$$/| $$  | $$\n");
    printf("|_______/ |__/|__/  |__/ \\_______/|__/       \\____  $$      |__/    \\______/ |__/  |__/\n");
    printf("                                             /$$  | $$                                 \n");
    printf("                                            |  $$$$$$/                                  \n");
    printf("                                             \\______/                                   \n");
    printf("                                                        author: Horja Razvan\n");
    printf("\n----------------------------------------------------------------------------------------\n\n");
}

int check_binarity(int **guess, int th) {
    for(int i = 0; i < th; i++) 
        for(int j = 0; j < th; j++)
            if(guess[i][j] != 0 && guess[i][j] != 1) {
                guess[i][j] = 0;
                return 0;
            }

    return 1;
}

int check_row(int **guess, int **board, int th, int rand) {
    for(int j = 0; j < th; j++)
        if(guess[rand][j] != board[rand][j]) return 0;

    return 1;
}