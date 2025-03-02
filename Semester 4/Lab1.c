/*
 *
 * Пустыню по прямой дороге пересекает машина.
 * Длина дороги S = 1000 км. Обьем бензобака - V = 500 литров.
 * На каждый километр машина тратит l = 2 литра бензина.
 * Машина может делать неограниченные запасы бензина в любых местах,
 * перевозить бензин только в бензобаке. Какое минимальное целое количество
 * бензобаков потребуется для пересечения пустыни?
 *
 */

#include <stdio.h>

#define Distance 1000
#define Volume 500
#define Expense 2

int main() {
  int tanks = 1;
  double max_distance = (double)Volume / Expense, stock = 0;

  while (stock + max_distance < Distance) {
    stock += 1.0 / (1 + 2 * tanks) * max_distance;
    tanks++;
  }

  printf("Tanks: %d\n", tanks);

  return 0;
}