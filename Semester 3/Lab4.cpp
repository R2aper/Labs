/*

Вариант - 3

TODO:

!Создать вектор из объектов класса "Коммуникационное устройство"

*Создать новый вектор, переписав в объекты с задержкой обработки информации меньшей 5 секунд

*Проверить, не оказался ли новый вектор пустым

*Если не пуст, повести сортировку объектов в новом векторе.

*/
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

class CommunicationDevice {
private:
  string Manufacturer;
  float Delay;

public:
  CommunicationDevice() {
    string Default = "Untitle";
    Manufacturer = Default;
    Delay = 0.0;
  }
  CommunicationDevice(string Manufacturer, float Delay) {
    this->Manufacturer = Manufacturer;
    this->Delay = Delay;
  }
  void setManufacturer(string newManufacturer) { Manufacturer = newManufacturer; }
  void setDelay(float newDelay) { Delay = newDelay; }
  string getManufacturer() { return Manufacturer; }
  float getDelay() { return Delay; }
  void printInfo() {
    cout << "Manufacturer: " << Manufacturer << endl;
    cout << "Delay: " << Delay << " seconds" << endl;
  }
};

void printVector(vector<CommunicationDevice> devices) {
  for (int i = 0; i < devices.size(); i++) {
    devices[i].printInfo();
  }
}

int main() {
  srand(time(0));
  string Manufacturers[5] = {"Apple", "Samsung", "Xiaomi", "Huawei", "Nokia"};
  vector<CommunicationDevice> devices(10);

  for (int i = 0; i < 3; i++) {
    devices[i].setDelay(rand() % 100);
    devices[i].setManufacturer(Manufacturers[rand() % 5]);
  }

  cout << "------Devices------" << endl;
  printVector(devices);

  vector<CommunicationDevice> new_devices;

  for (int i = 0; i < 3; i++) {
    if (devices[i].getDelay() < 30) {
      new_devices.push_back(devices[i]);
    }
  }

  if (new_devices.size() == 0) {
    cerr << "\nVector is empty!" << endl;
    return 1;
  }

  sort(new_devices.begin(), new_devices.end(),
       [](CommunicationDevice a, CommunicationDevice b) { return a.getDelay() < b.getDelay(); });

  cout << "\n----New Devices----" << endl;

  printVector(new_devices);

  return 0;
}
