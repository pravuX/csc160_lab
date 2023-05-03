#include <stdio.h>

int main() {
  int i, j, k;
  k = 3;
  for (i = 1, j = 2; i <= 10; i++, j+=k, k+=2) {
    printf("%d/%d + ", i, j);
  }
  printf("\b\b ");
  return 0;
}
