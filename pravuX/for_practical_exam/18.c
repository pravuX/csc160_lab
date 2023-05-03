#include <stdio.h>

long power(int a, int b) {
  if (b == 1)
    return a;
  return a * power(a, b-1);
}

int main() {
  int a, b;
  puts("Enter a and b");
  scanf("%d%d", &a, &b);
  printf("%d^%d = %ld", a, b, power(a, b));
  return 0;
}
