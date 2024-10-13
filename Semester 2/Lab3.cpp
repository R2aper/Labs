/*

Вариант - 14

TODO:

*Значение РАЗМЕРНОСТИ массива вводить с клавиатуры и память под массив отводить динамически.
*Исходные массивы заполнять, используя датчик случайных чисел.
*Новые массивы тоже создавать динамические
*Задать два массива X(n) и Y(k). Сформировать новые массивы , удалив из  исходных массивов все элементы, равные их минимальному значению.

*/

#include <climits>
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

int main() {
  srand(time(0));
  int min1 = INT_MAX, min2 = INT_MAX, n, k;

  cout << "Enter lenght of first massive" << endl;
  cin >> n;
  cout << "Enter lenght of second massive" << endl;
  cin >> k;

  if (n <= 0 || k <= 0)
    return 1;

  int *X = new int[n];
  int *Y = new int[k];

  for (int i = 0; i < n; i++)
    X[i] = rand();

  for (int i = 0; i < k; i++)
    Y[i] = rand();

  for (int i = 0; i < n; i++)
    cout << X[i] << " ";

  cout << endl;

  for (int i = 0; i < k; i++)
    cout << Y[i] << " ";

  for (int i = 0; i < n; i++) {
    if (X[i] < min1)
      min1 = X[i];
  }

  for (int i = 0; i < k; i++) {
    if (Y[i] < min2)
      min2 = Y[i];
  }

  int *Z = new int[n - 1];
  int *Q = new int[k - 1];

  for (int i = 0, j = 0; i < n; i++) {
    if (X[i] != min1) {
      Z[j] = X[i];
      j++;
    }
  }

  for (int i = 0, j = 0; i < k; i++) {
    if (Y[i] != min2) {
      Q[j] = Y[i];
      j++;
    }
  }

  cout << endl;

  for (int i = 0; i < n - 1; i++)
    cout << Z[i] << " ";

  cout << endl;

  for (int i = 0; i < k - 1; i++)
    cout << Q[i] << " ";

  delete[] X;
  delete[] Y;
  delete[] Z;
  delete[] Q;

  return 0;
}
