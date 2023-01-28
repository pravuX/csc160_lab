#include <math.h>
#include <stdio.h>
#define size 10
int set_U[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

/*
   For a set U of size, and its subsets A, B. we first order the set in any
   arbitary order. Then each of its subsets can be represented as an n length
   bitstring containing 1 if the element of the ith element U lies in A, and 0
   otherwise, where i = 0 .. n-1

   We use int arrays to represent bitstrings, and use a helper function to
   convert the bitstring to a decimal number such that bitwise operations can be
   easily performed without using loops on bitstrings.
*/

void toBinary(int decimal, int *bit_string) {
  int rem, quo, i;
  rem = quo = 0;
  i = size - 1;
  do {
    rem = decimal % 2;
    quo = decimal / 2;
    decimal = quo;
    bit_string[i] = rem;
    i--;
  } while (quo != 0 && i >= 0);
}

int search(int *arr, int el, int len) {
  int i, is_member = 0;
  for (int i = 0; i < len; i++) {
    if (arr[i] == el) {
      is_member = 1;
      break;
    }
  }
  return is_member;
}

void convertToBitString(int *set, int *bit_string) {
  int i;
  for (i = 0; i < size; i++) {
    bit_string[i] = search(set, set_U[i], 5);
  }
}

void showSetFromBitString(int *bit_string) {
  printf("{");
  for (int i = 0; i < size; i++) {
    if (bit_string[i] == 1) {
      printf("%3d", set_U[i]);
    }
  }
  printf("  }");
}

void set_intersection(int *bit_string_A, int *bit_string_B,
                      int *bit_string_Intersection) {
  for (int i = 0; i < size; i++) {
    bit_string_Intersection[i] = bit_string_A[i] && bit_string_B[i];
  }
}

void set_union(int *bit_string_A, int *bit_string_B, int *bit_string_Union) {
  for (int i = 0; i < size; i++) {
    bit_string_Union[i] = bit_string_A[i] || bit_string_B[i];
  }
}

int main() {
  int set_A[] = {1, 2, 3, 4, 5};
  int set_B[] = {2, 4, 6, 8, 10};
  int bit_string_A[size] = {0};
  int bit_string_B[size] = {0};
  int bit_string_Union[size] = {0};
  int bit_string_Intersection[size] = {0};
  int test[10] = {0};

  convertToBitString(set_A, bit_string_A);
  convertToBitString(set_B, bit_string_B);

  set_union(bit_string_A, bit_string_B, bit_string_Union);
  set_intersection(bit_string_A, bit_string_B, bit_string_Intersection);

  puts("Union of sets is");
  showSetFromBitString(bit_string_Union);
  puts("\nIntersection of sets is");
  showSetFromBitString(bit_string_Intersection);

  return 0;
}
