#include "stdio.h"

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

int main() {
    int set_A[] = {1, 2, 3, 4, 5};
    int set_B[] = {2, 4, 6, 8, 10};
    int i;
    for (i = 0; i < 5; i++) {
        printf("%3d", set_A[i]);
    }
    for (i = 0; i < 5; i++)
        if (!search(set_A, set_B[i], 5))
            printf("%3d", set_B[i]);
    return 0;
}
