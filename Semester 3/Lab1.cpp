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
        this->Manufacturer = Default;
        this->Delay = 0.0;
    }
    CommunicationDevice(string Manufacturer, float Delay) {
        this->Manufacturer = Manufacturer;
        this->Delay = Delay;
    }
    void setManufacturer(string newManufacturer) {
        this->Manufacturer = newManufacturer;
    }
    void setDelay(float newDelay) {
        this->Delay = newDelay;
    }
    string getManufacturer() {
        return this->Manufacturer;
    }
    float getDelay() {
        return this->Delay;
    }
    void printInfo()
   { 
       cout << "Manufacturer: " <<Manufacturer << endl;
       cout << "Delay: " <<Delay << " seconds" <<endl;
    }

};


int main() {
    string Manufacturer;
    float Delay;
    cout << "Enter manufacturer: \n";
    cin>>Manufacturer;
    cout << "Enter delay: \n";
    cin >> Delay;
            
    CommunicationDevice device;
    device.printInfo();

   return 0;
}