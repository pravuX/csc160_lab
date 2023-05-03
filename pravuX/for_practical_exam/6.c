#include <stdio.h>

int f(int x) {
  return 2 * x + 3;
}

int main() {
  int i;
  for (i = 1; i <= 10; i++)
    printf("(%d, %d), ", i, f(i));
  printf("\b\b ");

  return 0;
}
