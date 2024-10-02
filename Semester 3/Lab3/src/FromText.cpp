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

void FillFromFile(fstream &file, PopulationGrowth &obj) {
  string name;
  int growth2010, growth2011, growth2012, growth2013, growth2014;

  file >> name >> growth2010 >> growth2011 >> growth2012 >> growth2013 >>
      growth2014;
  obj.setName(name);
  obj.setGrowth2010(growth2010);
  obj.setGrowth2011(growth2011);
  obj.setGrowth2012(growth2012);
  obj.setGrowth2013(growth2013);
  obj.setGrowth2014(growth2014);
}

void writeToBin(ofstream &binfile, PopulationGrowth &obj) {
  unsigned nameLen = obj.GetName().size();
  string name = obj.GetName();
  int growth2010 = obj.GetGrowth2010(), growth2011 = obj.GetGrowth2011(),
      growth2012 = obj.GetGrowth2012(), growth2013 = obj.GetGrowth2013(),
      growth2014 = obj.GetGrowth2014();

  binfile.write((char *)&nameLen, sizeof(nameLen));
  binfile.write((char*)name.c_str(),name.size());
  binfile.write((char *)&growth2010, sizeof(growth2010));
  binfile.write((char *)&growth2011, sizeof(growth2011));
  binfile.write((char *)&growth2012, sizeof(growth2012));
  binfile.write((char *)&growth2013, sizeof(growth2013));
  binfile.write((char *)&growth2014, sizeof(growth2014));
}

void FromTextToBinary(fstream &file, ofstream &binfile, int all) {
  PopulationGrowth *Table = new PopulationGrowth[all];

  for (int i = 0; i < all; i++) 
    FillFromFile(file, Table[i]);
  
  binfile.write((char *)&all,sizeof(all));

  for (int i = 0; i < all; i++)
    writeToBin(binfile, Table[i]);

  delete[] Table;
}

int main() {
  setlocale(LC_ALL, "ru_RU.UTF-8");

  ofstream binFile;
  binFile.open("Table.bin", ios::binary);
  if (!binFile.is_open())
    return 1;

  fstream file;
  file.open("Table.txt");
  if (!file.is_open())
    return 1;

  int all = 0;
  file >> all;
  FromTextToBinary(file, binFile, all);
  binFile.close();
  file.close();

  return 0;
}
