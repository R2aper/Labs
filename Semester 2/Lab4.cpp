#include <iomanip>
#include <iostream>
#define n 50

using namespace std;

void input_matrix(int M[][n], int m) {
  srand(time(0));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++)
      M[i][j] = rand() % 100 - 50;
  }
}

void output_matrix(int M[][n], int m) {
  cout << endl;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      cout << setw(3) << M[i][j] << " ";
    }
    cout << endl;
  }
}

void change(int M[][n], int m) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++)
      M[i][j] = M[i][j] - (i + 1);
  }
}

int main() {

  int m, a[n][n];
  cin >> m;
  if (m <= 0)
    return 1;

  input_matrix(a, m);
  output_matrix(a, m);
  change(a, m);
  output_matrix(a, m);

  return 0;
}
