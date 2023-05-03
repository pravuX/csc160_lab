#include <stdio.h>

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int extended_gcd(int a, int b) {
  int r, r1, r2, t, t1, t2, i, q;
  // initilaize all variables
  i = 0;
  t1 = 0;
  t2 = 1;
  r1 = a;
  r2 = b;
  // implement the extended gcd algorithm
  while (r2 > 0) {
    q = r1 / r2;
    r = r1 % r2;
    r1 = r2, r2 = r;

    t = t1 - q * t2;
    t1 = t2, t2 = t;
  }
  return r1;
}

int main() {
  int a, b;
  puts("Enter a and b");
  scanf("%d%d", &a, &b);
  printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
  printf("extended_gcd(%d, %d) = %d", a, b, extended_gcd(a, b));
  return 0;
}
