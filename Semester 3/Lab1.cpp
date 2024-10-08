/*
Вариант 3

Создать класс "Коммуникационное устройство" которое должно содержать поля
"Производитель", Задержка обработки информации, а так же методы
для изменения, получения и вывода в консоль значений полей объекта

*/

#include <iostream>
#include <string>

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