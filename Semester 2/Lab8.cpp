// Вариант 14
// Сформировать новый список из сотрудников предприятия моложе 40 лет.
// Отсортировать этот список сотрудников в порядке возрастания из возраста
#include <iostream>
#include <string>
#define year 2024

using namespace std;

struct Employes {
  int id;
  string LastName;
  string initiials;
  string gender;
  int BirthYear;
  int StartYears;
};

int main() {
  int k = 10, count = 0;
  setlocale(LC_CTYPE, "ru_RU.UTF-8");
  Employes employers[10]{{1, "Анисимов", "Ю.П.", "М", 1970, 1989},
                         {2, "Иванов  ", "И.Н.", "М", 1980, 2002},
                         {3, "Махова  ", "О.И.", "Ж", 1960, 1980},
                         {4, "Огарев  ", "К.М.", "М", 1992, 2012},
                         {5, "Егорова  ", "П.К.", "Ж", 1990, 2011},
                         {6, "Голикова", "О.И.", "Ж", 1972, 1990},
                         {7, "Сотников", "Т.С.", "М", 1963, 1990},
                         {8, "Комов   ", "В.И.", "М", 1979, 2005},
                         {9, "Лебедев ", "А.А.", "М", 1959, 1981},
                         {10, "Димова  ", "В.В.", "Ж", 1991, 2010}};

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

  for (int i = 0; i < 10; i++) {
    cout << "|\t" << employers[i].id << "\t| " << employers[i].LastName
         << "\t|   " << employers[i].initiials << "    |    "
         << employers[i].gender << "\t     |    " << employers[i].BirthYear
         << "\t\t|     " << employers[i].StartYears << "\t    |" << endl;
  }

  cout << "____________________________________________________________________"
          "________________________________"
       << endl;
  for (int i = 0; i < k; i++) {
    if ((year - employers[i].BirthYear) < 40)
      count++;
  }

  Employes newemployers[count];
  int c = 0;
  for (int i = 0; i < k; i++) {
    if ((year - employers[i].BirthYear) < 40) {
      newemployers[c] = employers[i];
      c++;
    }
  }

  while (c--) {
    bool swapper = false;
    for (int i = 0; i < c; i++) {
      if (newemployers[i].BirthYear > newemployers[i + 1].BirthYear) {
        swap(newemployers[i], newemployers[i + 1]);
        swapper = true;
      }
    }
    if (swapper == false)
      break;
  }

  cout << endl;

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

  for (int i = 0; i < count; i++) {
    cout << "|\t" << newemployers[i].id << "\t| " << newemployers[i].LastName
         << "\t|   " << newemployers[i].initiials << "    |    "
         << newemployers[i].gender << "\t     |    "
         << newemployers[i].BirthYear << "\t\t|     "
         << newemployers[i].StartYears << "\t    |" << endl;
  }
  cout << "____________________________________________________________________"
          "________________________________"
       << endl;

  return 0;
}
