#include <stdio.h>
// chinese remainder theorem
// solve simulataneous linear congruences

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
    if (r1 == 1) // inverses exists
        // multiplicative inverse is t1 mod n
        i = t1 < 0 ? n + t1 : t1 % n;
    return i;
}

int main() {
  int i, x, M;
  int a[] = {1, 1, 3};
  int m[] = {5, 7, 11};
  int xi[3];
  int Mi[3] = {0};
  int sum_aMx = 0;
  puts("Given the following linear congruences");
  for (i = 0; i < 3; i++)
    printf("x ≡ %d (mod %d)\n", a[i], m[i]);
  // calculate M
  M = m[0] * m[1] * m[2];
  printf("M = %d\n", M);

  // calculate Mi for all mi
  // calculate xi such that Mi*xi mod mi = 1
  // i.e. inverse of Mi in mi
  puts("ai  Mi  xi ai*Mi*xi");
  for (i = 0; i < 3; i++) {
    Mi[i] = M / m[i];
    xi[i] = inverse(Mi[i], m[i]);
    sum_aMx += a[i] * Mi[i] * xi[i];
    printf("%-3d ", a[i]);
    printf("%-3d ", Mi[i]);
    printf("%-3d", xi[i]);
    printf("%-3d\n", a[i] * Mi[i] * xi[i]);
  }

  puts("The solution is sum(ai*Mi*xi) mod M");
  printf("x = %d", sum_aMx % M);
  return 0;
}
