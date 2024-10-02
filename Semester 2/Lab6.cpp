// 14. написать программу с рекурсивной функцией для вычисления значения
// суммы бесконечного ряда
// cos(x+b)
// E = 10^-4

#include <cmath>
#include <iostream>

using namespace std;

double f(float x, float b, int n) {
  double m = (pow(x, n) * cos(b + n * M_PI / 2)) / tgamma(n + 1);

  if (abs(m) < (0.5 * pow(10, -4))) {
    return m;
  }

  else {
    return m + f(x, b, n + 1);
  }
}

int main() {

  float x = 0.5, b = 5, n = 0;
  cout << "cos(" << x << "+" << b << ")=" << f(x, b, n) << endl;
  cout << cos(x + b) << endl;

  return 0;
}
