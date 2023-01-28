#include <stdio.h>

// a set of fuzzy pairs is called a fuzzy set
// a fuzzy pair consists of an element 'a' belonging to the universe of discourse
// and a membership 'u(a)' within the interval [0, 1], that is mapped from 'a'
// to [0, 1] by the membership function u(x);

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
  fuzzy_pair f1;
  f1.element = 10;
  f1.membership = 0.5;
  return 0;
}
