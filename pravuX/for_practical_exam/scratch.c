#include <stdio.h>
/*
 * Any subset of a Set A can be represented as an n-length bit string.
 * Here n is the number of elements, or the cardinal number of the set.
 * eg. A = { 3, 5, 2, 1 }
 * B = { 1, 2 }
 * B can be represented by the string '0011' where 0 corresponds to the
 * absence of an element of A in B while 1 corresponds to its presence.
 *
 * Using the bit string repesentation of subsets we can generate all
 * possible subsets for a given set. The basic principle is that, for
 * a set of size n, there are 2^n subsets including the empty set {} and
 * the set itself. The powerset of a set is the set of all of its
 * subsets.
 *
 * Generating subsets becomes a problem of generating combinations of
 * the indexes of the parent set. The number of subsets is equal to the
 * following sum, C(n, 0) + C(n, 1) + ... + C(n, n). Thus for each case
 * we generate all possible combinations of bit strings that correspond
 * to different subsets of A. For e.g. C(n, 0) corresponds to the empty
 * set and C(n, 3) corresponds to all the sets that can be formed by taking
 * 3 elements at a time from A.
 *
 * So for the Set A given above, 2^4 = 16 subsets are possible, all of
 * which can be represented by 16 4-bit strings viz.
 * 0000 0001 0010 0011 0100 0101 0110 0111
 * 1000 1001 1010 1011 1100 1101 1110 1111
 * We observe that these binary strings correspond to numbers 0 through 15
 *
 * Thus to find the subsets of A that can be formed by taking 'k'
 * elements at a time, we simply iterate from 0 to (2^size (here 4) - 1)
 * and for each integer(which represents a 4-bit string) in that range,
 * check the number of 1's, if the number of 1's is equal to 'k'
 * then we have a valid subset of A formed by taking 'k' elements at a time.
 * For the corresponding bitstring we display the subset and
 * move on to the next integer(bitstring).
 *
 * In this program no separate bitstring is created as when needed, we can
 * extract each bit from the integer and display the element of the set
 * corresponding to it. The show_subset function takes care of this
 * process of extracting bits and displaying the respective elements of
 * the parent set by msb masking.
 */

// calculate 2^x
int two_power(int a) {
  int i;
  int res = 1;
  for (i = 0; i < a; i++) {
    res *= 2;
  }
  return res;
}

int count_ones(int dec) {
  int count = 0;
  while(dec) {
    count += dec & 1; // add the lsb
    dec >>= 1; // shift to the right
  }
  return count;
}

void show_subset(int bin_str, int *set, int n) {
  int i;
  // to get the msb you need a binary number like this 10000;
  // the number of bits in such a number will depend of the
  // lenght of the bit string that represents the subset. For
  // example for a set of 3 elements, the msb_mask will be 100
  int msb_mask = two_power(n) >> 1; // 2^n / 2, n = no of elements
  putchar('{');
  for (i = 0; i < n; i++) {
    // display the element of the set if the msb is 1
    // 1 corresponds to the presence of ith element of the parent set
    // in the subset.
    if (bin_str & msb_mask) {
      printf("%d,", set[i]);
    }
    // next bit
    bin_str <<= 1;
  }
  printf("\b}");
}

void input_set(int *set, int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("Enter element %d: ", i+1);
    scanf("%d", &set[i]);
  }
}

void show_set(int *set, int n) {
  int i;
  putchar('{');
  for (i = 0; i < n; i++) {
    printf("%d,", set[i]);
  }
  printf("\b}\n");
}

// TODO: user input
int main() {
  int set[100] = {0};
  int n, i, k; // n = size of set/ no. of elements
  // k = nCk gives the number of possible subsets of the set
  // taking k at a time.
  // we start at 0 and go all the way up to n and for all
  // possible combination nCk we print the subsets.

  int no_of_binary_strings; // number of subsets

  // user input
  puts("Enter the number of elements: ");
  scanf("%d", &n);
  input_set(set, n);

  no_of_binary_strings = two_power(n);
  puts("The set is: ");
  show_set(set, n);
  printf("The power set is: \n{ {");
  for(k = 0; k <= n; k++)
    for (i = 0; i < no_of_binary_strings; i++)
      // test if the binary_str contains k one's
      // if that condition is true then it is a subset
      if(count_ones(i) == k) {
        show_subset(i, set, n);
        printf(", ");
      }
  printf("\b\b }");

  return 0;
}
