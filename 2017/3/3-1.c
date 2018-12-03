#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int main(int argc, char *argv[])
{

    int target = 289326;

    int x = 600;
    int y = 600;
    int grid[x + 100][y + 100];

    for (int i = 0; i < x + 100; i++) {
        for (int j = 0; j < y + 100; j++) {
            grid[i][j] = 0;
        }
    }

    int cX = (x / 2);
    int cY = (y / 2);

    int target_cX = 0;
    int target_cY = 0;

    int value = 0;

    while (1) {

        if (cY > y - 1 ||
                cY < 0 ||
                cX < 0 ||
                cX > x - 1) {
            break;
        }

        value++;
        grid[cY][cX] = value;

        if (value == target) {
            target_cX = cX;
            target_cY = cY;
        }

        int left = grid[cY][cX - 1];
        int right = grid[cY][cX + 1];
        int up = grid[cY - 1][cX];
        int down = grid[cY + 1][cX];
        int right_up = grid[cY - 1][cX + 1];
        int right_down = grid[cY + 1][cX + 1];
        int left_up = grid[cY - 1][cX - 1];
        int left_down = grid[cY + 1][cX - 1];

        /*
        [ ][ ][ ]
        [ ][x][ ]
        [ ][ ][ ]
        */
        if (!up &&
            !down &&
            !left &&
            !right &&
            !right_up &&
            !right_down &&
            !left_up &&
            !left_down) {
            cX++;
            continue;
        }

        /*
        [ ][ ][ ]
        [ ][x][x]
        [ ][ ][ ]
        */
        if (left && !up && !right) {
            cY--;
            continue;
        }

        /*
        [ ][ ][x]
        [ ][x][x]
        [ ][ ][ ]
        */
        if (down && !right && left_down && !left && !up) {
            cX--;
            continue;
        }

        /*
        [ ][X][x]
        [ ][x][x]
        [ ][ ][ ]
        */
        if (right && down && right_down && !left) {
            cX--;
            continue;
        }

        /*
        [x][x][x]
        [ ][x][x]
        [ ][ ][ ]
        */
        if (!up && !down && !left && right && right_down) {
            cY++;
            continue;
        }

        /*
        [x][x][x]
        [x][x][x]
        [ ][ ][ ]
        */
        if (up && !left && right && right_up && !down) {
            cY++;
            continue;
        }

        /*
        [x][x][x]
        [x][x][x]
        [x][ ][ ]
        */
        if (up && !down && !left && !right && right_up) {
            cX++;
            continue;
        }

        /*
        [x][x][x]
        [x][x][x]
        [x][x][ ]
        */
        if (up && !down && left && !right) {
            cX++;
            continue;
        }
        break;
    }

    int steps = ((target_cX - (x / 2)) + (target_cY - (x / 2)));

    printf("%d\n", steps);
    return 0;
}

