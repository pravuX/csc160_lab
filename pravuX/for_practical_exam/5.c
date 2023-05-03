#include <stdio.h>

int f(int x) {
  return 2 * x + 3;
}

int g(int x) {
  return 3 * x + 2;
}

int main() {
  int x;
  puts("f(x) = 2x + 3\ng(x) = 3x + 2\n");
  puts("Enter x:");
  scanf("%d", &x);
  printf("fog(%d) is ", x);
  printf("%d", f(g(x)));
  printf("\ngof(%d) is ", x);
  printf("%d", g(f(x)));
  return 0;
}
