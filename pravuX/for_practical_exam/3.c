#include <stdio.h>
const int universal_set[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

/* Returns 1 if element el is a memebr of the array arr */
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

void set_union(int *set_A, int *set_B, int len_A, int len_B) {
  int i;

  for (i = 0; i < len_A; i++) {
    printf("%3d", set_A[i]);
  }
  for (i = 0; i < len_B; i++)
    if (!search(set_A, set_B[i], len_A))
      printf("%3d", set_B[i]);
}
void set_inter(int *set_A, int *set_B, int len_A, int len_B) {
  int i;
  for (i = 0; i < len_B; i++)
    if (search(set_A, set_B[i], len_A))
      printf("%3d", set_B[i]);
}

void set_diff(int *set_A, int *set_B, int len_A, int len_B) {
  int i;
  for (i = 0; i < len_A; i++)
    if (!search(set_B, set_A[i], len_B))
      printf("%3d", set_A[i]);
}


int main() {
  int set_A[] = {1, 2, 3, 4, 5};
  int set_B[] = {2, 4, 6, 8, 10};
  int selection, exit_flag = 0; // false
  puts("A = { 1 2 3 4 5 }\nB = { 2 4 6 8 10 }\nU = { 1 2 3 4 5 6 7 8 9 10 }");
  while (!exit_flag) {
    puts("Choose the set operation:");
    puts("0: Union\n1: Intersection\n2: Difference\n3: Exit");
    fflush(stdin);
    printf("> ");
    scanf("%d", &selection);
    switch (selection) {
    case 0:
      printf("A ∪ B = {");
      set_union(set_A, set_B, 5, 5);
      printf("  }\n\n");
      break;
    case 1:
      printf("A ∩ B = {");
      set_inter(set_A, set_B, 5, 5);
      printf("  }\n\n");
      break;
    case 2:
      printf("A - B = {");
      set_diff(set_A, set_B, 5, 5);
      printf("  }\n\n");
      printf("B - A = {");
      set_diff(set_B, set_A, 5, 5);
      printf("  }\n\n");
      break;
    case 3:
      exit_flag = 1;
      break;
    default:
      puts("Invalid Selection!");
    }
  }
  return 0;
}
