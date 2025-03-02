/*
 *Найти число способов, какими можно разбить целое положительное число N на сумму целых
 *положительных чисел. Способы,  отличающиеся только порядком слагаемых, считаются как один способ.
 *Введите ответ для N = 10
 */

#include <stdio.h>

#define Number 10

int partition(int n, int max_val) {
  if (n == 0)
    return 1;
  if (n < 0 || max_val == 0)
    return 0;

  return (partition(n, max_val - 1) + partition(n - max_val, max_val));
}

int main() {
  printf("%d\n", partition(Number, Number));

  return 0;
}