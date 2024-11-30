/*

Вариант - 3

TODO:

*Написать программу, которая будет расчитывать значения функции по заданным данным и выводить график функции y(x)=e^|2.5+x|

*/

#include <QApplication>

#include "mainwindow.hpp"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowTitle("Lab8");
  w.show();
  return a.exec();
}
