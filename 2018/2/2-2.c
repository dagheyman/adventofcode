#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    #define STRLEN 26
    #define STRINGS 250
    #define INPUT_FILE "input.txt"

    char str[250];
    char input[STRINGS][STRLEN];

    for (int a=0; a < STRINGS; a++) {
        for (int b = 0; b < STRLEN; b++) {
            input[a][b] = 0;
        }
    }

    FILE *fp = fopen(INPUT_FILE, "r");
    if(fp == NULL) {
        return 1;
    }
    int c = 0;
    while (fgets(str, 250, fp) != NULL) {
        for (int d = 0; d < strlen(str); d++) {
            input[c][d] = str[d];
        }
        c++;
    }
    fclose(fp);

    int global_high_score=0;
    for (int d=0; d < STRINGS; d++) {
        int high_score = 0;
        for (int e=0; e < STRINGS; e++) {
            int score = 0;
            for (int f = 0; f < STRLEN; f++) {
                if (input[d][f] == input[e][f]) {
                    score++;
                }
            }
            if (score >= high_score && score != STRLEN) {
                high_score = score;
            }
        }
        if (high_score >= global_high_score) {
            global_high_score=high_score;
            for (int f = 0; f < STRLEN; f++) {
                printf("%c", input[d][f]);
            }
            printf(" %d \n", high_score);
        }
    }
}
