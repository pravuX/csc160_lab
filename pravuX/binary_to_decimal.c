#include <stdio.h>
#include <math.h>
#define size 8 // maximum number of bits in a binary number

int to_decimal(char *bit_string) {
  int num, i, pos;
  num = 0;
  i = size - 1;
  pos = 0;
  while (i >= 0) {
    if (bit_string[i]) {
      num += (bit_string[i] - 48) * (int) pow(2, pos);
      pos++;
    }
    i--;
  }
  putchar('\n');
  return num;
}

int main() {
  char bit_string[size] = {0};
  int dec;
  fscanf(stdin, "%s", bit_string);
  dec = to_decimal(bit_string);
  return 0;
}
