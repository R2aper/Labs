/*

Вариант - 14

TODO:

* Сформировать новый список из сотрудников предприятия моложе 40 лет.
* Отсортировать этот список сотрудников в порядке возрастания из возраста

*/

#include <iostream>
#include <string>

#define year 2024

using namespace std;

struct Employer {
  int id;
  string LastName;
  string initiials;
  string gender;
  int BirthYear;
  int StartYears;
};

void PrintEmployers(Employer employers[], int size) {
  cout << "____________________________________________________________________"
          "________________________________"
       << endl;
  cout << "|     Номер\t"
       << "| Фамилия    "
       << "   | Инициалы"
       << "  |   Пол          "
       << "| Дата рождения\t"
       << "| Дата начала работы|" << endl;
  cout << "____________________________________________________________________"
          "________________________________"
       << endl;

  for (int i = 0; i < size; i++) {
    cout << "|\t" << employers[i].id << "\t| " << employers[i].LastName << "\t|   "
         << employers[i].initiials << "    |    " << employers[i].gender << "\t     |    "
         << employers[i].BirthYear << "\t\t|     " << employers[i].StartYears << "\t    |" << endl;
  }

  cout << "____________________________________________________________________"
          "________________________________"
       << endl;
}

void SortEmployers(Employer employers[], int size) {
  while (size--) {
    bool swapper = false;
    for (int i = 0; i < size; i++) {
      if (employers[i].BirthYear > employers[i + 1].BirthYear) {
        swap(employers[i], employers[i + 1]);
        swapper = true;
      }
    }
    if (swapper == false)
      break;
  }
}

int main() {
  setlocale(LC_CTYPE, "RUS");
  int k = 10, c = 0, count = 0;
  Employer employers[10] = {
      {1, "Анисимов", "Ю.П.", "М", 1970, 1989},  {2, "Иванов  ", "И.Н.", "М", 1980, 2002},
      {3, "Махова  ", "О.И.", "Ж", 1960, 1980},  {4, "Огарев  ", "К.М.", "М", 1992, 2012},
      {5, "Егорова  ", "П.К.", "Ж", 1990, 2011}, {6, "Голикова", "О.И.", "Ж", 1972, 1990},
      {7, "Сотников", "Т.С.", "М", 1963, 1990},  {8, "Комов   ", "В.И.", "М", 1979, 2005},
      {9, "Лебедев ", "А.А.", "М", 1959, 1981},  {10, "Димова  ", "В.В.", "Ж", 1991, 2010}};

  PrintEmployers(employers, k);

  for (int i = 0; i < k; i++) {
    if ((year - employers[i].BirthYear) < 40)
      count++;
  }

  Employer NewEmployers[count];

  for (int i = 0; i < k; i++) {
    if ((year - employers[i].BirthYear) < 40) {
      NewEmployers[c] = employers[i];
      c++;
    }
  }

  SortEmployers(NewEmployers, c);

  PrintEmployers(NewEmployers, c);

  return 0;
}
