// iterative implementation of the gcd algorithm
#include <stdio.h>

int gcd(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b; // remainder of a / b
        a = b, b = r;
    }
    return a;
}

int main() {
    int a, b;
    puts("Enter two numbers to find the GCD");
    scanf("%d%d",&a,&b);
    printf("GCD is %d.", gcd(a, b));
    return 0;
}
