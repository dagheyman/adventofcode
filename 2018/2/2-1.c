#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int hits = 0;
    int three = 0;
    int two = 0;
    int twos = 0;
    int threes = 0;

    char str[250];
    FILE *fp = fopen("input.txt", "r");
    if(fp == NULL) {
        return 1;
    }
    int i = 0;
    while (fgets(str, 250, fp) != NULL) {
        two = 0;
        three = 0;
        for (int c = 0; c < strlen(str); c++) {
            hits = 0;
            for (int d = 0; d < strlen(str); d++) {
                if (str[c] == str[d]) {
                    hits++;
                }
            }
            if (hits == 2) {
                two = 1;
            }
            if (hits == 3) {
                three = 1;
            }
        }
        if (two) {
            twos++;
        }
        if (three) {
            threes++;
        }
        i++;
    }
    fclose(fp);

    printf("%d\n", twos * threes);
}
