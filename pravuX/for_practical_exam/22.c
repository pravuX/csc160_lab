#include <stdio.h>

int factorial(int n) {
  if (n==0)
    return 1;
  return n * factorial(n-1);
}

// nCr
int c(int n, int r) {
    return factorial(n) / (factorial(n-r) * factorial(r));
}

int main() {
    int n, i , j;
    puts("Enter the number of rows to print:");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        // print spaces in front of the triangle
        for (j = n - i; j > 0; j--) {
            printf("  ");
        }
        for (j = 0; j <= i; j++) {
            printf("%-4d", c(i, j));
        }
        putchar('\n');
    }
}
