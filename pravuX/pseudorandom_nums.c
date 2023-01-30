#include <stdio.h>

int main() {
  int x, a, c, m, n, i;
  puts("Enter sled value");
  scanf("%d", &x);
  puts("Enter constants a and b");
  scanf("%d%d", &a, &c);
  puts("Enter modulus");
  scanf("%d", &m);
  puts("Enter number of random numbers to generate");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    x = (a * x + c) % m;
    printf("%-3d", x);
  }

  return 0;
}
