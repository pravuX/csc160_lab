int count_ones(int num) {
  /* counts the number of ones in the binary
  representation of an integer by shifting and
  adding each bit to the count accumulator. */
  int count = 0;
  while(num) {
    count += num & 1; // add the lsb
    num >>= 1; // shift to the right
  }
  return count;
}
