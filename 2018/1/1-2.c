#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int temperature = 0;
    int diff = 0;
    char str[10000];
    int temps[1000000] = {0};
    int diffs[999] = {0};

    FILE *fp = fopen("input.txt", "r");
    if(fp == NULL) {
        return 1;
    }

    int i = 0;
    while (fgets(str, 10000, fp) != NULL) {
        if (str[0] == '-') {
            memmove(str, str + 1, strlen(str));
            diff = (0 - atoi(str));
            diffs[i] = diff;
        }
        if (str[0] == '+') {
            memmove(str, str + 1, strlen(str));
            diff = atoi(str);
            diffs[i] = diff;
        }
        i++;
    }
    fclose(fp);

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
}
