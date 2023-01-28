#include <stdio.h>

int floor(float x) {
  return (int) x;
}

int ceil(float x) {
  return (int) x + 1;
}

int main() {
  printf("floor(2.7) = %d\n", floor(2.7));
  printf("ceil(2.1) = %d\n", ceil(2.1));
  return 0;
}
