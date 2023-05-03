#include <stdio.h>

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  int a, b;
  puts("Enter a and b");
  scanf("%d%d", &a, &b);
  if (gcd(a, b) == 1)
    printf("%d and %d are coprime.", a, b);
  else
    printf("%d and %d are not coprime.", a, b);
  return 0;
}
