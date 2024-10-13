/*

Вариант - 14

TODO:

* В заданном предложении заменить все строчные латинские буквы прописными.

*/

#include <iostream>
#include <string>

using namespace std;

int main() {
  setlocale(LC_ALL, "ru_RU.UTF-8");
  string a;
  cout << "Enter word:\n";
  getline(cin, a);

  for (int b = 0; b < a.length(); b++) {
    if (a[b] > 123 || a[b] < 96)
      a[b] = a[b];
    else
      a[b] = a[b] - 32;
  }

  cout << a;

  return 0;
}
