#include <cmath>
#include <iomanip>
#include <iostream>


#include "../include/mylib.hpp"

#define M_PI 3.14159265358979323846

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

int SumOfMainDiagonal(int **M, int m) {
  int sum = 0;
  for (int i = 0; i < m; i++) {
    sum += M[i][i];
  }

  return sum;
}

int factorial(int n) {
  if (n == 0 || n == 1)
    return 1;
  else
    return n * factorial(n - 1);
}

double approx(float x, float b, int n) {
  double eps = 0.5 * pow(10, -4);
  double m = (pow(x, n) * cos(b + n * M_PI / 2)) / factorial(n);

  if (abs(m) < eps) {
    return m;
  }

  else {
    return m + approx(x, b, n + 1);
  }
}