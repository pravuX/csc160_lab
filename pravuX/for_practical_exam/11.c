#include <stdio.h>

int main() {
  int a, b;
  puts("Enter values of a and b");
  scanf("%d%d", &a, &b);
  printf("%d", a >= 0 ? a - a/b * b : b + a);
  return 0;
}
