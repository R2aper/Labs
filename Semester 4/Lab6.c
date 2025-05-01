#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING "ABCDEF"
#define FRAGMENT "CDE"
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct SearchResult {
  int comparisons;
  bool found;
} SearchResult;

SearchResult brute_force(const char *T, const char *F) {
  int n = strlen(T);
  int m = strlen(F);
  int comparisons = 0;
  bool found = false;

  for (int i = 0; i <= n - m; ++i) {
    int j;
    for (j = 0; j < m; ++j) {
      comparisons++;
      if (T[i + j] != F[j]) {
        break;
      }
    }
    if (j == m) {
      found = true;
      break;
    }
  }
  return (SearchResult){comparisons, found};
}

// Should be freed
int *bad_char_table(const char *F) {
  int *table = malloc(256 * sizeof(int));
  for (int i = 0; i < 256; i++)
    table[i] = -1;

  for (int i = 0; i < strlen(F); i++)
    table[(unsigned char)F[i]] = i;

  return table;
}

SearchResult boyer_moore_search(const char *T, const char *F) {
  int n = strlen(T);
  int m = strlen(F);
  int comparisons = 0;
  bool found = false;

  int *bad_char = bad_char_table(F);
  int s = 0;
  while (s <= n - m) {
    int j = m - 1;
    while (j >= 0 && F[j] == T[s + j]) {
      comparisons++;
      j--;
    }
    if (j < 0) {
      found = true;
      break;
    } else {
      int bad_char_shift = j - bad_char[(unsigned char)T[s + j]];
      s += MAX(1, bad_char_shift);
    }
  }
  free(bad_char);
  return (SearchResult){comparisons, found};
}

int main() {
  char *T = STRING, *F = FRAGMENT;

  SearchResult bfResult = brute_force(T, F);
  printf("Последовательный поиск: %d сравнений, ", bfResult.comparisons);
  printf(bfResult.found ? "подстрока найдена\n" : "подстрока не найдена\n");

  SearchResult bmResult = boyer_moore_search(T, F);
  printf("Метод Бойера-Мура: %d сравнений, ", bmResult.comparisons);
  printf(bmResult.found ? "подстрока найдена\n" : "подстрока не найдена\n");

  return 0;
}