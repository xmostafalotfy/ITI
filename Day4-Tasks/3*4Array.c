#include <stdio.h>

#define COLS 4
#define ROWS 3

int main() {
    int arr[ROWS][COLS] = {0}, rowSum = 0;
    float colAvg[COLS] = {0};

    for (int row = 0; row < ROWS; row++) {
        rowSum = 0;
        for (int col = 0; col < COLS; col++) {
            int valid = 0; // Flag to track valid input
            while (!valid) {
                printf("\nEnter positive num [%d][%d]: ", row, col);

                if (scanf("%d", &arr[row][col]) == 1 && arr[row][col] > 0) {
                    valid = 1;
                    rowSum += arr[row][col];
                    colAvg[col] += arr[row][col];
                } else {
                    printf("Only positive integers are accepted!\n");

                    while (getchar() != '\n');
                }
            }
        }
        printf("\nSum of row %d is: %d", row, rowSum);
        if (row == ROWS - 1) {
            for (int col = 0; col < COLS; col++) {
                printf("\nAverage of column [%d] is: %.2f", col, (colAvg[col] / ROWS));
            }
        }
    }
    return 0;
}
