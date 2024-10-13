/*

Вариант - 3

TODO:

!Создать вектор из объектов класса "Коммуникационное устройство"

*Создать новый вектор, переписав в объекты с задержкой обработки информации меньшей 5 секунд

*Проверить, не оказался ли новый вектор пустым

*Если не пуст, повести сортировку объектов в новом векторе.

*/
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
    this->Manufacturer = Default;
    this->Delay = 0.0;
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
    cout << "\nManufacturer: " << Manufacturer << endl;
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
  vector<CommunicationDevice> devices(3);

  for (int i = 0; i < 3; i++) {
    devices[i].setDelay(rand() % 10);
    devices[i].setManufacturer(Manufacturers[rand() % 5]);
  }

  cout << "------Devices------" << endl;
  printVector(devices);

  vector<CommunicationDevice> new_devices;

  for (int i = 0; i < 3; i++) {
    if (devices[i].getDelay() < 5) {
      new_devices.push_back(devices[i]);
    }
  }

  if (new_devices.size() == 0) {
    cerr << "\nVector is empty!" << endl;
    return 1;
  }

  for (int i = 0; i < new_devices.size() - 1; i++) {
    for (int j = i + 1; j < new_devices.size(); j++) {
      if (new_devices[i].getDelay() > new_devices[j].getDelay()) {
        CommunicationDevice temp = new_devices[i];
        new_devices[i] = new_devices[j];
        new_devices[j] = temp;
      }
    }
  }

  cout << "\n----New Devices----" << endl;

  printVector(new_devices);

  return 0;
}
