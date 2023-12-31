#include <stdio.h>

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
    printf("\nrepo: https://github.com/thek0d3r/Binary-Fun.git\n");
    printf("\n----------------------------------------------------------------------------------------\n\n");
}


void print_screen(int **board, int *nums, int th) {
    print_banner();

    for(int i = 0; i < th; i++) {
        printf("%4d  ", *(nums+i));
        for(int j = 0; j < th; j++)
            printf("%d ", *(*(board+i)+j));
        printf("\n");
    }
}