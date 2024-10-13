/*

Вариант - 14

TODO:

* Написать программу с рекурсивной функцией для вычисления значения суммы бесконечного ряда cos(x+b)
*P.S. eps = 0,5 * 10^-4

*/

#include <cmath>
#include <iostream>

#define M_PI 3.14159265358979323846 

using namespace std;

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

int main() {

  float x = 0.5, b = 5, n = 0;
  cout << "cos(" << x << "+" << b << ")=" << approx(x, b, n) << endl;
  cout <<"cmath:" <<cos(x + b) << endl;

  return 0;
}
