// Значение РАЗМЕРНОСТИ массива вводить с клавиатуры и память под
// массив отводить динамическую ( используя операцию NEW).
// Исходные массивы заполнять, используя датчик случайных чисел.
// Новые массивы тоже создавать динамические

// Задать два массива X(n) и Y(k). Сформировать новые массивы , удалив из
// исходных массивов все элементы, равные их минимальному значению.

#include <climits>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  srand(time(0));
  int n, k, min1 = INT_MAX, min2 = INT_MAX;

  cout << "Enter lenght of first massive" << endl;
  cin >> n;
  cout << "Enter lenght of second massive" << endl;
  cin >> k;

  if (n <= 0 || k <= 0)
    return 1;

  int *X = new int(n);
  int *Y = new int(k);

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

  for (int i = 0; i < n; i++) {
    if (X[i] == min1) {
      X[i] = 0;
    }
  }

  for (int i = 0; i < k; i++) {
    if (Y[i] == min2)
      Y[i] = 0;
  }

  cout << endl;
  for (int i = 0; i < n; i++)
    cout << X[i] << " ";
  cout << endl;
  for (int i = 0; i < k; i++)
    cout << Y[i] << " ";

  delete X;
  delete Y;

  return 0;
}
