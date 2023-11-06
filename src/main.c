#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "board.h"

int th, score;
int* board;

int main() {

    gen_random_seed();

    printf("Introduceti dimensiunea tablei: ");
    scanf("%d", &th);

    getchar();

    board = (int*)calloc(9, sizeof(int));

    gen_board(board, th);
    
    for(int i = 0; i < th; i++) {
        char* guess = (char*)calloc(9, sizeof(char));

        printf("Introduceti reprezentarea in binar pentru numarul %d: ", board[i]);
        fgets(guess, 9, stdin);

        while(!validate_guess(guess)) {
            printf("Numarul introdus este invalid!\n");

            guess = (char*)calloc(9, sizeof(char));

            printf("Introduceti reprezentarea in binar pentru numarul %d: ", board[i]);
            fgets(guess, 9, stdin);
        }

        getchar();

        int result = check_guess(board[i], strtol(guess, NULL, 2));

        if(result) {
            printf("Corect!\n");
            score++;
        } else printf("Gresit!\n");

        getchar();
    
        free(guess);
    }

    printf("Scorul tau este: %d", score);

    free(board);
    return 0;
}