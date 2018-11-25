#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int sum = 0;
    int i = 0;
    int number = 0;
    int opposite_number = 0;

    char *input = argv[1];
    int input_len = strlen(input);

    for (i = 0; i < input_len; i++) {

        number = input[i] - '0';

        if (i < input_len / 2 ) {
            opposite_number = input[i + input_len / 2] - '0';
        } else {
            opposite_number = input[i - input_len / 2] - '0';
        }

        if (number == opposite_number) {
            sum += number;
        }
    }

    printf("%d\n", sum);
    return 0;
}
