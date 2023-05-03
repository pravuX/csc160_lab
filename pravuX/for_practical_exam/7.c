#include <stdio.h>

int my_floor(float x) {
  return (int) x;
}

int my_ceil(float x) {
  return (int) x + 1;
}

int main() {
  float x;
  puts("Enter any real number:");
  scanf("%f", &x);
  printf("floor(%.2f) = %d\n", x, my_floor(x));
  printf("ceil(%.2f) = %d", x, my_ceil(x));
  return 0;
}
