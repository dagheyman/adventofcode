#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int sum = 0;
    int i = 0;
    int number = 0;
    int next_number = 0;

    char *input = argv[1];
    int input_len = strlen(input);

    for (i = 0; i < input_len; i++) {

        number = input[i] - '0';

        if (i == input_len - 1) {
            next_number = input[0] - '0';
        } else {
            next_number = input[i + 1] - '0';
        }

        if (number == next_number) {
            sum += number;
        }
    }

    printf("%d\n", sum);
    return 0;
}
