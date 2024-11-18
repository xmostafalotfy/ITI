#include <stdio.h>
#include <unistd.h>

int main() {
    int n;

    printf("Enter the order of the square: ");

    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("Only odd numbers are acceptable \n");
        return 0;
    }

    int i = 1;
    int row = 0, col = n / 2;

    while (i <= n * n) {

        printf("\033[%d;%dH", row  + 2, col * 4 + 2);

        printf("%d ", i);

        int newRow = row - 1;
        int newCol = col + 1;

        if (newRow < 0)
            newRow = n - 1;
        if (newCol >= n)
            newCol = 0;

        if (i % n == 0) {
            newRow = row + 1;
            newCol = col;
        }

        row = newRow;
        col = newCol;

        i++;
        fflush(stdout);
        sleep(1);
    }


    return 0;
}
