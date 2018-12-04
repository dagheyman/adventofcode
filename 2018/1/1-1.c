#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int temperature = 0;
    int diff = 0;
    char str[1000];

    FILE *fp = fopen("input.txt", "r");
    if(fp == NULL) {
        return 1;
    }

    while (fgets(str, 10000, fp) != NULL) {
        if (str[0] == '-') {
            memmove(str, str + 1, strlen(str));
            diff = atoi(str);
            temperature -= diff;
        }
        if (str[0] == '+') {
            memmove(str, str + 1, strlen(str));
            diff = atoi(str);
            temperature += diff;
        }
    }
    fclose(fp);

    printf("%d\n", temperature);
    return 0;
}
