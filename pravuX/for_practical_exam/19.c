#include <stdio.h>

long factorial(int n) {
  if (n == 0)
    return 1;
  return n * factorial(n-1);
}

long nPk(int n, int k) {
  return factorial(n) / factorial(n - k);
}

int is_vowel(char ch) {
  char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
  int i;
  for (i = 0; i < 5; i++) {
    if (ch == vowels[i])
      return 1;
  }
  return 0;
}

int main() {
  char word[25];
  int len;
  int n_vowels = 0;
  int n_of_odd_positions;
  puts("Enter a word");
  scanf("%s", word);
  // get the length of the word
  // and count the number of vowels
  for (len = 0; word[len]!='\0'; len++) {
    if (is_vowel(word[len]))
      n_vowels++;
  }
  n_of_odd_positions = len % 2 == 0 ? len / 2 : len / 2 + 1;
  printf("The number of permutations of the letter of %s such that the vowels always occur in odd places is %ld.", word, nPk(n_of_odd_positions, n_vowels) * factorial(len-n_vowels));
  return 0;
}
