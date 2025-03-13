/*
 *Дано: размер пустой квадратной шахматной доски N = 12
 *Найти: число всех возможных расстановок N ферзей на доске.
 */

#include <stdbool.h>
#include <stdio.h>

// Размер доски
#define N 12

// Безопасное размещение ферзя

bool isSafe(int board[N][N], int row, int col, long long *solutions) {
  int i, j;

  // Проверка строки слева
  for (i = 0; i < col; i++)
    if (board[row][i])
      return false;

  // Проверка верхней диагонали слева
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j])
      return false;

  // Проверка нижней диагонали слева
  for (i = row, j = col; j >= 0 && i < N; i++, j--)
    if (board[i][j])
      return false;

  return true;
}

void solveNQueens(int board[N][N], int col, long long *solutions) {
  // База рекурсии: если все ферзи размещены
  if (col >= N) {
    (*solutions)++;
    return;
  }

  // Пробуем разместить ферзя в каждом ряду текущей колонки
  for (int i = 0; i < N; i++) {
    if (isSafe(board, i, col, solutions)) {
      board[i][col] = 1;

      // Рекурсивно размещаем остальные ферзи
      solveNQueens(board, col + 1, solutions);

      board[i][col] = 0;
    }
  }
}

int main() {
  // Инициализация пустой доски
  int board[N][N] = {0};
  long long solutions = 0;

  // Начинаем решение с первой колонки
  solveNQueens(board, 0, &solutions);

  // Вывод результата
  printf("Количество решений для %dx%d доски: %lld\n", N, N, solutions);

  return 0;
}