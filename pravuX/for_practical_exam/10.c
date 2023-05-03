#include <stdio.h>

int main() {
  int i, j, sum;
  sum = 0;
  for (i = 1; i <= 5; i++) {
    for (j = 1; j <= 4; j++) {
      sum += i * j;
    }
  }

  printf("Sum is %d.", sum);

  return 0;
}
