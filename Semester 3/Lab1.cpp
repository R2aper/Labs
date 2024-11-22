/*

Вариант - 3

TODO:

!Создать класс "Коммуникационное устройство" которое должно содержать поля:

*"Производитель"
*Задержка обработки информации

!И методы:

*Для изменения полей
*Получения полей
*Вывода в консоль значений полей объекта

*/

#include <iostream>
#include <string>

using namespace std;

class CommunicationDevice {
private:
  string Manufacturer;
  float Delay;

public:
  CommunicationDevice() : Manufacturer("Untitle") { Delay = 0.0; }

  CommunicationDevice(const string &Manufacturer, float Delay) {
    this->Manufacturer = Manufacturer;
    this->Delay = Delay;
  }

  void setManufacturer(const string &newManufacturer) { Manufacturer = newManufacturer; }
  void setDelay(float newDelay) { Delay = newDelay; }

  const string &getManufacturer() { return Manufacturer; }
  float getDelay() { return Delay; }

  void printInfo() {
    cout << "Manufacturer: " << Manufacturer << endl;
    cout << "Delay: " << Delay << " seconds" << endl;
  }
};

int main() {
  string Manufacturer;
  float Delay;
  cout << "Enter manufacturer: \n";
  cin >> Manufacturer;
  cout << "Enter delay: \n";
  cin >> Delay;

  CommunicationDevice device;
  device.printInfo();

  return 0;
}