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

using namespace std;

class HashTable {
private:
  vector<vector<pair<char, int>>> table;

  // Хэш-функция, возвращает индекс буквы [0, 25]
  int hash(char c) { return tolower(c) - 'a'; }

public:
  HashTable() : table(TABLE_SIZE) {}

  // Увеличивает частоту буквы в хэш-таблице
  void Increment(char key) {
    key = tolower(key);
    int index = hash(key);

    for (auto &p : table[index]) {
      if (p.first == key) {
        p.second++;
        return;
      }
    }

    table[index].push_back(make_pair(key, 1));
  }

  // Удаляет букву из хэш-таблицы
  // True - при успехе, False - если буквы нет
  bool Remove(char key) {
    key = tolower(key);
    int index = hash(key);

    auto &bucket = table[index];
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
      if (it->first == key) {
        bucket.erase(it);
        return true;
      }
    }

    return false;
  }

  int getValue(char key) {
    key = tolower(key);
    int index = hash(key);

    for (const auto &p : table[index]) {
      if (p.first == key)
        return p.second;
    }

    return 0;
  }

  void PrintToFile(ofstream &out) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
      for (const auto &p : table[i])
        out << p.first << ": " << p.second << endl;
    }
  }
};

string GetText(ifstream &in) {
  string str;
  char c;
  while (in.get(c))
    str += c;

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

  cout << "Enter a key: ";
  string input;
  getline(cin, input);

  int val = ht.getValue(input[0]);
  cout << input[0] << ": " << val << endl;

  return 0;
}