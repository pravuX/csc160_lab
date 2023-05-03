#include <stdio.h>

int fact(int n) {
  if (n == 1)
    return n;
  return n * fact(n - 1);
}

int main() {
  int len;
  char word[30];
  printf("Enter the word: ");
  scanf("%s", word);
  for (len = 0; word[len] != '\0'; len++);
  printf("%d words can be from \"%s\" with or without meaning.", fact(len), word);
  return 0;
}
