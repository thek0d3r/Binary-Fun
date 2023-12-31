#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "board.h"
#include "screen.h"

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #elif __APPLE__
        system("clear");
    #else
        printf("\033c");
    #endif
}

int main() {

    int th;
    int **board, **guess;
    int *nums;
    int opt, row, gameOn = 1, correctRows = 0;

    time_t start_time, end_time;
    double elapsed_time;

    gen_random_seed();

    clear_screen();
    print_banner();

    printf("Introduceti dimensiunea tablei: ");
    scanf("%d", &th);

    getchar();

    board = (int**)calloc(th, sizeof(int*));
    guess = (int**)calloc(th, sizeof(int*));
    nums = (int*)calloc(th, sizeof(int));

    if(board == NULL || nums == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        exit(0);
    }

    for (int i = 0; i < th; i++) {
        *(board+i) = (int*)calloc(th, sizeof(int));
        *(guess+i) = (int*)calloc(th, sizeof(int));
        if (*(board+i) == NULL || *(guess+i) == NULL) {
            printf("Eroare la alocarea memoriei pentru randul %d!\n", i);
            exit(0);
        }
    }

    gen_board(board, nums, th);

    time(&start_time);

    do {
        // clear_screen();
        print_screen(guess, nums, th);

        printf("\nOptiuni: \n");
        printf("0. Iesire\n");
        printf("1. Completare rand\n");
        printf("Introduceti optiunea dorita: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 0: 
            printf("Jocul a fost abandonat!\n");
            free(board);
            free(nums);
            free(guess);
            exit(0);

        case 1: {
            printf("\nIntroduceti indexul randului pe care vreti sa il completati (0, %d): ", th-1);
            scanf("%d", &row);

            if(row < 0 || row > th - 1) {
                printf("Rand invalid! Indexul randului trebuie sa fie intre 0 si %d\n", th-1);
                break;
            }

            if(check_row(guess, board, th, row)) {
                printf("Randul este deja completat corect!\n");
                sleep(3);
                break;
            }

            printf("\nIntroduceti valorile randului (cu spatiu intre ele): ");

            for(int j = 0; j < th; j++) {
                scanf("%d", *(*(guess+row)+j));
            }

            if(!check_binarity(guess, th)) {
                printf("\nNu ati introdus o reprezentare in binar pentru randul %d!\n", row);
                sleep(3);
                break;
            }
            
            if(!check_row(guess, board, th, row)) {
                printf("Valoarea introdusa este incorecta!\n");
                sleep(3);
                break;
            } else correctRows++;
            
            if(correctRows == th) {
                time(&end_time);
                gameOn = 0;
            }

            break;
        }
        
        default:
            printf("Optiunea este invalida!");
            sleep(3);
            break;
        }
    } while(gameOn);

    clear_screen();
    print_screen(guess, nums, th);

    elapsed_time = difftime(end_time, start_time);

    printf("\nJocul s-a terminat in %.2f secunde!\n", elapsed_time);

    free(board);
    free(nums);
    free(guess);

    return 0;
}