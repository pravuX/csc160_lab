#include <stdio.h>

int sum_digits(int number) {
  if (number == 0)
    return 0;
  return number % 10 + sum_digits(number / 10);
}

int main() {
  int num;
  puts("Enter a number");
  scanf("%d", &num);
  printf("The sum of its digits is %d.", sum_digits(num));
  return 0;
}
