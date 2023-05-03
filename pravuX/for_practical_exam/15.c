#include <stdio.h>

// To find the multiplicative inverse of a number 'b' in the set 'Zn'
void inverse(int b, int n, int *result_arr) {
    int r, r1, r2, t, t1, t2, i1, i2, q;
    // initilaize all variables
    i1 = i2 = 0;
    t1 = 0;
    t2 = 1;
    r1 = n;
    r2 = b;
    // implement the extended gcd algorithm
    while (r2 > 0) {
        q = r1 / r2;
        r = r1 % r2;
        r1 = r2, r2 = r;

        t = t1 - q * t2;
        t1 = t2, t2 = t;
    }
    if (r1 == 1) {// multiplicative inverse exists
        // multiplicative inverse is t1 mod n
        i1 = t1 < 0 ? n + t1 : t1 % n;
        i2 = (-r1 * b) % n;
    }
    result_arr[0] = i1;
    result_arr[1] = n + i2;
}

int main() {
    int n, b;
    int inverses[] = {0, 0};
    puts("Enter value n for Zn");
    scanf("%d", &n);
    printf("Enter value b to find inverses in Z%d\n", n);
    scanf("%d", &b);
    inverse(b, n, inverses);
    printf("The multiplicative inverse of %d in Z%d is %d.\n", b, n, inverses[0]);
    printf("The additive inverse of %d in Z%d is %d.\n", b, n, inverses[1]);
    return 0;
}
