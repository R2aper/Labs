/*

Вариант - 14

TODO:

*Опередить сумму всех элементов матрицы. Сформировать массив из элементов, расположенных выше
главной диагонали.

*/

#include <iomanip>
#include <iostream>

using namespace std;

int main() {

  srand(time(0));
  const int l = 2;
  int input, sum = 0, m[l][l], n[l];

  cout << "1 for type 2 for rand" << endl;
  cin >> input;

  switch (input) {
  case (1):
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < l; j++)
        cin >> m[i][j];
    }

    break;

  case (2):
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < l; j++)
        m[i][j] = rand() % (100 + 100) - 100;
    }

    break;

  default:
    return 1;
  }

  cout << "Matrix:" << endl;

  for (int i = 0; i < l; i++) {
    for (int j = 0; j < l; j++)
      cout << setw(5) << m[i][j];
    cout << endl;
  }

  cout << endl;

  for (int i = 0; i < l; i++) {
    for (int j = 0; j < l; j++) {
      sum += m[i][j];
    }
  }

  for (int i = 0; i < l; i++) {
    n[i] = m[i][i];
  }

  cout << "Diagonal:" << endl;
  for (int i = 0; i < l; i++) {
    cout << setw(5) << n[i];
  }

  cout << endl << "Sum: " << sum << endl;

  return 0;
}