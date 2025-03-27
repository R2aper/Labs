/*
!Требуется написать программу на языке С++.
*    Данные считываются из входного файла input.txt
*    Результат выводится в выходной файл output.txt
!Необходимо
*    составить  хеш-таблицу, содержащую буквы и количество их вхождений в считанном тексте
*    реализовать функции добавления, удаления и поиска элементов в хеш-таблице.
*    в программе:
*        считать входной файл input.txt, содержащий текст на английском языке.
*        вывести полученную таблицу в файл output.txt.
*        сделать поиск введенной  с клавиатуры буквы в хеш-таблице и вывести значение на экран.
*/

#include <cctype>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

#define TABLE_SIZE 26
#define HASH_CODE 5381
#define QUADRATIC_PROBING(index, attempt) ((index + attempt * attempt) % TABLE_SIZE)

using namespace std;

class HashTable {
private:
  vector<pair<char, int>> table;

  // Хэш-функция, алгоритм djb2
  size_t hash(const string &str) {
    unsigned long hash = HASH_CODE;

    for (char c : str) {
      hash = ((hash << 5) + hash) + static_cast<unsigned char>(c); // hash * 33 + c
    }
    return hash;
  }

public:
  HashTable() : table(TABLE_SIZE) {
    for (int i = 0; i < TABLE_SIZE; i++)
      table[i] = {'\0', 0};
  }

  // Увеличивает частоту буквы в хэш-таблице
  void Increment(char key) {
    int index = hash(string({key})) % TABLE_SIZE;

    for (int i = 0; i < table.size(); i++) {
      int current = QUADRATIC_PROBING(index, i); // Квадратичный шаг

      if (table[current].first == '\0') { // Если буквы нет
        table[current].first = key;
        table[current].second = 1;
        return;
      }

      if (table[current].first == key) {
        table[current].second++;
        return;
      }
    }
  }

  // Удаляет букву из хэш-таблицы
  // True - при успехе, False - если буквы нет
  bool Remove(char key) {
    int index = hash(string({key})) % TABLE_SIZE;

    for (int i = 0; i < table.size(); i++) {
      int current = QUADRATIC_PROBING(index, i); // Квадратичный шаг

      if (table[current].first == key) {
        table[current].first = '\0';
        table[current].second = 0;
        return true;
      }
    }
    return false;
  }

  size_t getValue(char key) {
    int index = hash(string({key})) % TABLE_SIZE;

    for (int i = 0; i < table.size(); i++) {
      int current = QUADRATIC_PROBING(index, i); // Квадратичный шаг

      if (table[current].first == key)
        return table[current].second;
    }

    return 0;
  }

  void Print() {
    for (const auto &p : table)
      cout << p.first << ": " << p.second << endl;
  }

  void PrintToFile(ofstream &out) {
    for (const auto &p : table)
      out << p.first << ": " << p.second << endl;
  }
};

string GetText(ifstream &in) {
  string str;
  char c;
  while (in.get(c))
    str += tolower(c);

  in.close();
  return str;
}

int main() {
  HashTable ht;

  ifstream in("input.txt");
  if (!in) {
    cerr << "Cannot open input.txt" << endl;
    return 1;
  }

  string text = GetText(in);
  for (char c : text) {
    if (isalpha(c))
      ht.Increment(c);
  }

  ofstream out("output.txt");
  if (!out) {
    cerr << "Cannot open output.txt" << endl;
    return 1;
  }

  ht.PrintToFile(out);
  out.close();

  cout << "Enter a key to get value: ";
  string input;
  getline(cin, input);

  int val = ht.getValue(input[0]);
  cout << input[0] << ": " << val << endl;

  cout << "Enter a key to remove: ";
  string input2;
  getline(cin, input2);

  if (!ht.Remove(input2[0])) {
    cerr << "No key to remove!" << endl;
    return 1;
  }

  cout << ": " << ht.getValue(input2[0]) << endl;
  return 0;
}
