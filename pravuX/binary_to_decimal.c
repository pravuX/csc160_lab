#include <stdio.h>
#include <math.h>
#define size 10 // maximum number of bits in a binary number

int toDecimal(int *bit_string) {
  int num, i;
  num = 0;
  i = size - 1;
  while (i >= 0) {
    num += bit_string[i] * (int) pow(2, size-i-1);
    i--;
  }
  return num;
}

int main() {

}
