#include <stdio.h>


void show_b(int *b, int row, int col) {
  int i, j;
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++)
      printf("%-3d", *(b + i*col + j));
    putchar('\n');
  }
}

int main() {
  int i, j, k;
  int b_A[2][3] = {{1, 0, 1},
                   {0, 1, 0}};
  int b_B[2][3] = {{0, 1, 0},
                   {1, 1, 0}};
  int b_C[3][2] = {{1, 0},
                   {0, 1},
                   {1, 0}};
  int b_D[2][3] = {{1, 1, 0},
                   {0, 1, 1}};
  int prodct[3][3] = {0};

  puts("Boolean Matrix A is");
  show_b(b_A[0], 2, 3);
  puts("Boolean Matrix B is");
  show_b(b_B[0], 2, 3);
  puts("Boolean Matrix C is");
  show_b(b_C[0], 3, 2);
  puts("Boolean Matrix D is");
  show_b(b_D[0], 2, 3);

  puts("Join of A and B is");
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++)
      printf("%-3d", b_A[i][j] || b_B[i][j]);
    putchar('\n');
  }

  puts("Meet of A and B is");
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++)
      printf("%-3d", b_A[i][j] && b_B[i][j]);
    putchar('\n');
  }

  puts("Product of C and D is");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 2; k++) {
        prodct[i][j] = prodct[i][j] || (b_C[i][k] && b_D[k][j]);
      }
    }
  }
  show_b(prodct[0], 3, 3);

  return 0;
}
