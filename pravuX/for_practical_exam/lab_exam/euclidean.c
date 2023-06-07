#include <stdio.h>

long gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

long extended_gcd(int a, int b) {
  int r, r1, r2, t, t1, t2, i, q;
  // initialize all variables
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
  printf("gcd(24, 38) = %ld\n", gcd(24, 38));
  printf("extended_gcd(24, 38) = %ld", extended_gcd(24, 38));
  return 0;
}
