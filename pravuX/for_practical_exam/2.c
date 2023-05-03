#include <stdio.h>
// to find the cartesian product of two given sets

void input_set(int *set, int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("Enter element %d: ", i+1);
    scanf("%d", &set[i]);
  }
}

int main() {
  int set_A[100] = {0};
  int set_B[100] = {0};
  int n_A, n_B, i, j;

  puts("Enter the number of elements of A");
  scanf("%d", &n_A);
  input_set(set_A, n_A);

  puts("Enter the number of elements of B");
  scanf("%d", &n_B);
  input_set(set_B, n_B);

  puts("The cartesian product is:");
  printf("AxB = { ");
  for (i = 0; i < n_A; i++) {
    for (j = 0; j < n_B; j++) {
      printf("(%d, %d), ", set_A[i], set_B[j]);
    }
  }
  printf("\b\b }");


  return 0;
}
