/*
 *Дано: размер пустой квадратной шахматной доски N = 12
 *Найти: число всех возможных расстановок N ферзей на доске.
 */

#include <stdbool.h>
#include <stdio.h>

// Размер доски
#define N 12

// Глобальная переменная для подсчета решений
long long solutions = 0;

// Функция проверки безопасности размещения ферзя
bool isSafe(int board[N][N], int row, int col) {
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

// Рекурсивная функция для решения задачи
void solveNQueens(int board[N][N], int col) {
  // База рекурсии: если все ферзи размещены
  if (col >= N) {
    solutions++;
    return;
  }

  // Пробуем разместить ферзя в каждом ряду текущей колонки
  for (int i = 0; i < N; i++) {
    if (isSafe(board, i, col)) {
      // Размещаем ферзя
      board[i][col] = 1;

      // Рекурсивно размещаем остальные ферзи
      solveNQueens(board, col + 1);

      // Убираем ферзя (backtracking)
      board[i][col] = 0;
    }
  }
}

int main() {
  // Инициализация пустой доски
  int board[N][N] = {0};

  // Начинаем решение с первой колонки
  solveNQueens(board, 0);

  // Вывод результата
  printf("Количество решений для %dx%d доски: %lld\n", N, N, solutions);

  return 0;
}

/*

#include <stdio.h>
#include <stdlib.h>

int count = 0; // Глобальный счетчик допустимых расстановок

// Рекурсивная функция для размещения ферзей
void solve(int row, int n, int* cols) {
    if (row == n) {
        count++; // Увеличиваем счетчик при успешной расстановке
        return;
    }

    for (int col = 0; col < n; col++) {
        int is_safe = 1;
        // Проверка безопасности позиции (col, row)
        for (int prev_row = 0; prev_row < row; prev_row++) {
            int prev_col = cols[prev_row];
            // Проверка столбца и диагоналей
            if (prev_col == col || abs(prev_col - col) == row - prev_row) {
                is_safe = 0;
                break;
            }
        }
        if (is_safe) {
            cols[row] = col; // Запоминаем позицию ферзя
            solve(row + 1, n, cols); // Рекурсия для следующей строки
        }
    }
}

int main() {
    const int N = 12;
    int* cols = (int*)malloc(N * sizeof(int)); // Массив для хранения позиций

    if (cols == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    solve(0, N, cols); // Начинаем с первой строки (0)
    free(cols);

    printf("Количество расстановок: %d\n", count);
    return 0;
}

*/