#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    int c[16];
    int checksum = 0;

    char buffer[100];
    FILE *fp = fopen("input.txt", "r");

    do {

        if(fp == NULL) {
            break;
        }

        int ret = sscanf(buffer, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
                &c[0], &c[1], &c[2], &c[3], &c[4], &c[5], &c[6], &c[7], &c[8],
                &c[9], &c[10], &c[11], &c[12], &c[13], &c[14], &c[15]);

        if (ret != -1) {
            for (i = 0; i < 16; i++) {
                for (j = 0; j < 16; j++) {
                    if (c[i] == c[j]) {
                        continue;
                    }
                    if ((c[i] % c[j]) == 0) {
                        checksum += (c[i] / c[j]);
                    }
                }
            }
        }
    } while (fgets(buffer, sizeof(buffer), fp));
    fclose(fp);
    printf("%d\n", checksum);
    return 0;
}
