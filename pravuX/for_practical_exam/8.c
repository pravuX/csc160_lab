#include <stdio.h>

float min(float a, float b) {
  return a < b ? a : b;
}

float max(float a, float b) {
  return a < b ? b : a;
}

float comp(float x) {
  return 1.0 - x;
}

typedef struct fuzzy_pair {
  float element;
  float membership;
} fuzzy_pair;

int main() {
  int i;
  fuzzy_pair set_A[5] = {{1, 0.5}, {2, 0.8}, {3, 0.2}, {4, 0.3}, {5, 0.6}};
  fuzzy_pair set_B[5] = {{1, 0.2}, {2, 0.4}, {4, 0.1}, {4, 0.8}, {5, 0.9}};
  fuzzy_pair set_intersection[5];
  fuzzy_pair set_union[5];
  fuzzy_pair set_complement[5];

  puts("The sets are");
  printf("A = {");
  for (i = 0; i < 5; i++) {
    printf("(%.2f, %.2f), ", set_A[i].element, set_A[i].membership);
  }
  printf("\b\b}");

  printf("\nA = {");
  for (i = 0; i < 5; i++) {
    printf("(%.2f, %.2f), ", set_B[i].element, set_B[i].membership);
  }
  printf("\b\b}\n");

  printf("A ∩ B = {");
  for (i = 0; i < 5; i++) {
    printf("(%.2f, %.2f), ", set_A[i].element, min(set_A[i].membership, set_B[i].membership));
  }
  printf("\b\b}\n");

  printf("A ∪ B = {");
  for (i = 0; i < 5; i++) {
    printf("(%.2f, %.2f), ", set_A[i].element, max(set_A[i].membership, set_B[i].membership));
  }
  printf("\b\b}\n");

  printf("A' = {");
  for (i = 0; i < 5; i++) {
    printf("(%.2f, %.2f), ", set_A[i].element, comp(set_A[i].membership));
  }
  printf("\b\b}\n");

  return 0;
}
