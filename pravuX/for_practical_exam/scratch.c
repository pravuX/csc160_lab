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
  fuzzy_pair set_A[5] = {{1, 0.5}, {2, 0.8}, {3, 0.2}, {4, 0.3}, { 5, 0.6}};
  fuzzy_pair set_B[5] = {{}, {}, {}, {}, {}};
  return 0;
}
