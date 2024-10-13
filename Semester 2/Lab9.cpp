/*

Вариант - 14

TODO:
* Текстовый файл содержит информацию из табл. 12.

* Используя данные этого файла рассчитать «Добыто на сумму».

*/

#include <fstream>
#include <iomanip>
#include <iostream>

#define path "12Tab.txt"

using namespace std;

struct Brigada {
  int id;
  float price;
  float monday;
  float tuesday;
  float wendesday;
  float thursday;
  float friday;
  float allPrice;
};

void print(Brigada *brigada, int all) {
  cout << " __________________________________________________________________" << endl;
  cout << "|ID " << setw(8) << "|Price " << setw(8) << "|Monday " << setw(8) << "|Tuesday "
       << setw(1) << "|Wendesday " << setw(8) << "|Thursday " << setw(8) << "|Friday " << setw(8)
       << "|allPrice|";
  for (int i = 0; i < all; i++) {
    cout << endl
         << "|" << brigada[i].id << setw(4) << "|" << brigada[i].price << setw(4) << "|"
         << brigada[i].monday << setw(4) << "|" << brigada[i].tuesday << setw(5) << "|"
         << brigada[i].wendesday << setw(7) << "|" << brigada[i].thursday << setw(6) << "|"
         << brigada[i].friday << setw(4) << "|" << brigada[i].allPrice << "   |";
  }
  cout << endl << " __________________________________________________________________" << endl;
}

int main() {
  int all, i = 0;

  ifstream fin;
  fin.open(path);

  if (!fin.is_open()) {
    cerr << "Error!";
    return 1;
  }

  fin >> all;
  Brigada *brigada = new Brigada[all];
  for (int i = 0; !fin.eof(); i++) {
    fin >> brigada[i].id >> brigada[i].price >> brigada[i].monday >> brigada[i].tuesday >>
        brigada[i].wendesday >> brigada[i].thursday >> brigada[i].friday;

    brigada[i].allPrice = brigada[i].monday + brigada[i].tuesday + brigada[i].wendesday +
                          brigada[i].thursday + brigada[i].friday;
  }

  print(brigada, all);

  fin.close();

  delete[] brigada;

  return 0;
}