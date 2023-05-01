void to_binary_str(int *bin_str, int dec, int n) {
  // masking with 1(bitwise ANDing) to obtain the lsb
  // shifting right to obtain each bit
  int i = n - 1;
  while (i >= 0) {
    // effectively the same as dec % 2
    bin_str[i] = dec & 1;
    // right shifting is the same as dividing by 2
    // you can also do dec /= 2;
    dec >>= 1;
    i--;
  }
}

int main() {
  return 0;
}
