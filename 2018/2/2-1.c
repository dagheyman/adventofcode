#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    char *input[250];

    char str[10000];
    FILE *fp = fopen("input.txt", "r");
    if(fp == NULL) {
        return 1;
    }

    int i = 0;
    while (fgets(str, 10000, fp) != NULL) {
            input[i] = str;
        i++;
    }
    fclose(fp);

    int twos = 0;
    int threes = 0;
    int hits = 0;
    int checksum = 0;
    for(int j = 0; j < 250; j++) {
        for (int k = 0; k < strlen(input[j]); k++) {
            hits = 0;
            printf("J %d K %d TESTING %s", j, k, input[j]);
            for (int l = 0; l < strlen(input[j]); l++) {
                if (input[j][k] == '\n') {
                    continue;
                }
                if (input[j][k] == input[j][l]) {
                    printf("HIT: %c\n", input[j][k]);
                    hits++;
                }
            }
            if (hits == 2) {
                printf("HITS %d\n", hits);
                twos++;
            }
            if (hits == 3) {
                printf("HITS %d\n", hits);
                threes++;
            }
        }
    }
    checksum = twos * threes;
    printf("%d\n", checksum);


    /*
    int l = 0;
    int m = 0;
    while(1) {
        if (l == 999) {
            l = 0;
            m += 999;
        }
        temperature += diffs[l];
        for (int n = 0; n < l + m; n++) {
            if (temperature == temps[n]) {
                printf("%d\n", temperature);
                return 0;
            }
        }
        temps[l + m] = temperature;
        l++;
    }
    */
}
