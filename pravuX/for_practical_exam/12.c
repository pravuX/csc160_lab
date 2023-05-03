#include <stdio.h>
/*
 * Miller Rabin Primality Testing.
 * - for a given odd number n > 1, determines if it is composite
 *   or probably prime.
 * - it is a probabilistic primality test
 */

long power(int a, int b) {
  int i = 0;
  long res = 1;
  for (i = 0; i < b; i++) {
    res *= a;
  }
  return res;
}

void find_k_m(int *k, int *m, int n) {
  int i = 0;
  n -= 1;
  // to solve n-1 = 2^k * m
  // keep dividing n-1 by 2 untill it becomes odd
  // count the number of times it was divided by 2 = k
  // final value of n that is odd = m
  while (n % 2 == 0) {
    i += 1;
    n /= 2;
  }
  *k = i;
  *m = n;
}

int main() {
  int n, k, m, i, a;
  long x;
  n = 9;
  a = 2; // chose a base that is between 1 and n-1
  find_k_m(&k, &m, n); // determine k and m
  x = power(a, m) % n; // find x = a^ m mod n

  if (x == 1 || x == n - 1) {
    printf("PRIME (PROBABLY)");
    return 0;
  }

  // repeat k-1 times
  for (i = 0; i < k - 1; i++) {
    x = power(x, 2) % m;
    if (x == n - 1) {
      printf("PRIME (PROBABLY)");
      return 0;
    }
    if (x == 1) {
      printf("COMPOSITE");
      return 0;
    }
  }
  return 0;
}
