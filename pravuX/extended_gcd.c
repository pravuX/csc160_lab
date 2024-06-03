// To find the multiplicative inverse of a number 'b' in the set 'Zn'
#include <stdio.h>

int inverse(int b, int n) {
    int r, r1, r2, t, t1, t2, i, q;
    // initilaize all variables
    i = 0;
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
    if (r1 == 1) {// inverse exists
        // inverse is t1 mod n
        i = t1 < 0 ? n + t1 : t1 % n;
      return i;
    }
    return -1;
}

int main() {
    int n, b, i;
    puts("Enter value n for Zn");
    scanf("%d", &n);
    printf("Enter value b to find multiplicate inverse in Z%d\n", n);
    scanf("%d", &b);
    i = inverse(b, n);
    if (i != -1)
      printf("The inverse of %d in Z%d is %d.", b, n, i);
    else
      printf("The inverse does not exist.");
    return 0;
}
