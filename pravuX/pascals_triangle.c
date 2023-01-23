/*
   print the pascal's trianlge of n given rows
   we use Pascal's identity to find the geometric
   arrangement of binomial coefficents in a triangle
   i.e. The Pascal's triangle is laid out as follows
    0C0
    1C0 1C1
    2C0 2C1 2C2
    ... up to n rows
*/

// n!
#include <stdio.h>

int factorial(int n) {
    int f;
    int i;
    f = 1;
    i = 1;
    while (i <= n) {
        f *= i;
        i++;
    }
    return f;
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
/*
   by introducing a net int variable c representing the coefficent
   the above for loop can be written as follows

   it uses the pascal's identity that states that
   nCr = (n-1)Cr * n / n-r

for(i=0; i<n; i++) {
    for(j=1; j <= n-i; j++)
        printf("  ");

    for(j=0; j <= i; j++) {
        if (j==0 || i==0)
            coef = 1;
        else
            coef = coef*(i-j+1)/j;

        printf("%-4d", coef);
    }
    printf("\n");
}
*/
