/*

Вариант - 14

TODO:

* Вычитание из значения каждого элемента матрицы номера строки данного элемента.

*/

#include <iomanip>
#include <iostream>

using namespace std;

void input_matrix(int **M, int m) {
  srand(time(0));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++)
      M[i][j] = rand() % 100 - 50;
  }
}

void output_matrix(int **M, int m) {
  cout << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      cout << setw(3) << M[i][j] << " ";
    }
    cout << endl;
  }
}

void change(int **M, int m) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++)
      M[i][j] = M[i][j] - (i + 1);
  }
}

int main() {

  int m, **a;
  cout << "Enter size of matrix: " << endl;
  cin >> m;
  if (m <= 0)
    return 1;

  a = new int *[m];
  for (int i = 0; i < m; i++)
    a[i] = new int[m];

  input_matrix(a, m);
  output_matrix(a, m);
  change(a, m);
  output_matrix(a, m);

  for (int i = 0; i < m; i++)
    delete[] a[i];

  delete[] a;

  return 0;
}
