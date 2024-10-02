/*
TODO:
-Разработать КЛАСС для создания объектов с полями из текстового файла согласно
вашему варианту.

- Написать первую программу, которая считывает информацию из созданного
текстового файла в поля объекта и записывает ее в двоичный (бинарный ) файл

-Написать вторую программу, которая считывает информацию из двоичного
(бинарного) файла и упорядочит информацию, расположив названия областных центров
в алфавитном порядке. После повторного чтения двоичного файла результат работы
выводится на экран.

*/
#include <fstream>
#include <iostream>
#include <string>

#include "../include/lib.hpp"

using namespace std;

void ToAlphabet(PopulationGrowth *Table, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (Table[i].GetName() > Table[j].GetName()) {
        PopulationGrowth temp = Table[i];
        Table[i] = Table[j];
        Table[j] = temp;
      }
    }
  }
}

void readFromBin(ifstream &binfile, PopulationGrowth &obj) {
  unsigned nameLen;
  string name;
  int growth2010, growth2011, growth2012, growth2013, growth2014;

  binfile.read((char *)&nameLen, sizeof(nameLen));
  name.resize(nameLen);
  binfile.read((char *)name.data(), nameLen);
  binfile.read((char *)&growth2010, sizeof(growth2010));
  binfile.read((char *)&growth2011, sizeof(growth2011));
  binfile.read((char *)&growth2012, sizeof(growth2012));
  binfile.read((char *)&growth2013, sizeof(growth2013));
  binfile.read((char *)&growth2014, sizeof(growth2014));

  obj.setName(name);
  obj.setGrowth2010(growth2010);
  obj.setGrowth2011(growth2011);
  obj.setGrowth2012(growth2012);
  obj.setGrowth2013(growth2013);
  obj.setGrowth2014(growth2014);

}

void fromBinaryToText(ifstream &binfile) {
  int all = 0;
  binfile.read((char *)&all,sizeof(all));
  PopulationGrowth *a = new PopulationGrowth[all];
  for (int i = 0; i < all; i++)
    readFromBin(binfile, a[i]);

  ToAlphabet(a, all);

  for (int i = 0; i < all; i++)
    a[i].Print();

}

int main() {
  setlocale(LC_ALL, "ru_RU.UTF-8");

  ifstream binFile2;
  binFile2.open("Table.bin", ios::binary);
  if (!binFile2.is_open())
    return 1;

  fromBinaryToText(binFile2);
  binFile2.close();

  return 0;
}
