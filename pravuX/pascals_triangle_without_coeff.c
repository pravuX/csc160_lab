#include <stdio.h>

void print_row(int* row, int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", row[i]);
    putchar('\n');
}

void pretty_print_row(int* row, int size, int no_of_rows) {
    int i;
    for (i = no_of_rows - 1; i >= size; i--)
        printf("  ");
    for (i = 0; i < size; i++)
        printf("%-4d", row[i]);
    putchar('\n');
}

int main()
{
    int i, j, n;
    int l_num, temp;
    int row[20];
    puts("Enter the no. of rows to print:");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        /*
           i goes from 0 to n, counting our rows.
           We observe that for ith row the number of elements in the row is i+1

           First we check is we are printing only up to two rows, and in that case
           we populate the row array with all 1's

           Then for all more than 2 rows to be printed, we form the row as follows:
               - initialize the left number(l_num) to be 0
               - for each ith row, we populate it from indices j = 0 to i-1.
               - we populate it by:
                                - storing the jth element into a temporary variable.
                                - adding l_num to the jth element.
                                - changing the l_num to be previous jth element for next iteration.
               - at last we append 1 to the row.

            Finally we print the row.
        */
        if (i <= 1) {
            for (j = 0; j <= i; j++)
                row[j] = 1;
        } else {
            l_num = 0;
            for (j = 0; j <= i-1; j++) {
                // store element at jth index of current row as tmp
                temp = row[j];
                // find jth element for new row
                row[j] += l_num;
                // assign l_num for next iteration
                l_num = temp;
            }
            row[j] = 1;
        }
        pretty_print_row(row, i+1, n);
    }
    return 0;
}
