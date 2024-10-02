/*
Вариант - 3

-Создать вектор из объектов класса "Коммуникационное устройство"

-Создать новый вектор, переписав в объекты с задержкой обработки информации меньшей 5 секунд
(критерий для перезаписи выберите
самостоятельно)

-Проверить, не оказался ли новый вектор пустым

-Если не пуст, повести сортировку объектов в новом векторе. 
(критерий сортировки тоже выберите сами, исходя из атрибутов
объектов вашего класса)

*/
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>

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
    srand(time(0));
    string Manufacturers[5] = {"Apple", "Samsung", "Xiaomi", "Huawei", "Nokia"};
    vector <CommunicationDevice> devices(3);

    for(int i =0; i < 3; i++){ 
        devices[i].setDelay(rand() % 10);//!
        devices[i].setManufacturer(Manufacturers[rand() % 5]);
    }

    vector <CommunicationDevice> new_devices;
    for(int i =0; i < 3; i++){ 
        if(devices[i].getDelay() < 5){//!
            new_devices.push_back(devices[i]);
        }
    }

    if(new_devices.size() == 0){
        cerr << "Vector is empty" << endl;
        return 1;
    }

    sort(new_devices.begin(), new_devices.end(), [](CommunicationDevice a, CommunicationDevice b) {//!
        return a.getDelay() < b.getDelay();
    });

    for(int i =0; i < new_devices.size(); i++){ 
        new_devices[i].printInfo();
    }

    return 0;
}