#include <stdio.h>
#define SIZE 10
int set_U[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void show_set(int *set, int len) {
  int i;
  printf("{ ");
  for (i = 0; i < len; i++) {
    printf("%d ", set[i]);
  }
  printf("}\n");
}

void show_bit_string(int *set, int len) {
  int i, j, bit;
  for (i = 0; i < SIZE; i++) {
    for (bit = 0, j = 0; j < len; j++) {
      if (set_U[i] == set[j]) {
        bit = 1;
        break;
      }
    }
    printf("%d", bit);
  }
  putchar('\n');
}

int main() {
  int set_A[] = {1, 2, 3, 4, 5};
  int set_B[] = {2, 4, 6, 8, 10};
  printf("U = ");
  show_set(set_U, 10);
  printf("A = ");
  show_set(set_A, 5);
  printf("B = ");
  show_set(set_B, 5);
  puts("The bitstring representations are:");
  printf("A = ");
  show_bit_string(set_A, 5);
  printf("B = ");
  show_bit_string(set_B, 5);

  return 0;
}
