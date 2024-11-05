/*

Вариант - 3

TODO:

*Составить программу, которая содержит текущую информацию о заявках на авиабилеты.

!Каждая заявка содержит:
* пункт назначения;
* номер рейса;
* фамилию и инициалы пассажира;
* желаемую дату вылета.

!Программа должна обеспечивать:
* хранение всех заявок в виде списка;
* добавление заявок в список;
* удаление заявок;
* вывод заявок по заданному номеру рейса и дате вылета;
* вывод всех заявок.

*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

using namespace std;

class AirTicket {
private:
  string destination;
  string flightNumber;
  string name;
  string date;

public:
  AirTicket() {
    destination = "";
    flightNumber = "";
    name = "";
    date = "";
  }

  AirTicket(string destination, string flightNumber, string name, string date) {
    this->destination = destination;
    this->flightNumber = flightNumber;
    this->name = name;
    this->date = date;
  }

  void SetDestination(string destination) { this->destination = destination; }
  void SetFlightNumber(string flightNumber) { this->flightNumber = flightNumber; }
  void SetName(string name) { this->name = name; }
  void SetDate(string date) { this->date = date; }

  string GetDestination() { return destination; }
  string GetFlightNumber() { return flightNumber; }
  string GetName() { return name; }
  string GetDate() { return date; }

  friend ostream &operator<<(ostream &out, const AirTicket &data) {
    out << "Пунк назначения: " << endl << data.destination << endl;
    out << "Номер рейса: " << endl << data.flightNumber << endl;
    out << "Фамилия и инициалы: " << endl << data.name << endl;
    out << "Дата: " << endl << data.date << endl;

    return out;
  }
};

class AirTicketDataBase {
private:
  list<AirTicket> data;

public:
  AirTicketDataBase() { data = {}; }

  AirTicketDataBase(list<AirTicket> data) { this->data = data; }

  list<AirTicket> GetData() { return data; }

  void AddData(AirTicket data) { this->data.push_back(data); }

  void DeleteData(string flightNumber, string date) { //!
    data.remove_if([flightNumber, date](AirTicket i) {
      return (i.GetFlightNumber() == flightNumber && i.GetDate() == date);
    });
  }

  void PrintDataBase() {
    cout << "\x1b[2J\x1b[H";
    copy(data.begin(), data.end(), ostream_iterator<AirTicket>(cout, "\n"));
  }

  void PrintAirTicket(string flightNumber, string date) { //!
    cout << "\x1b[2J\x1b[H";
    auto it = find_if(data.begin(), data.end(), [flightNumber, date](AirTicket i) {
      return (i.GetFlightNumber() == flightNumber && i.GetDate() == date);
    });

    if (it != data.end())
      cout << *it;

    else
      cout << "Заявка не найдена" << endl;
  }
};

void EnterData(AirTicketDataBase &DataBase) {
  string destination, flightNumber, name, date;
  cout << "Введите пункт назначения: " << endl;
  getline(cin, destination);
  cout << "Введите номер рейса: " << endl;
  getline(cin, flightNumber);
  cout << "Введите фамилию и инициальны пассажира: " << endl;
  getline(cin, name);
  cout << "Введите дату вылета: " << endl;
  getline(cin, date);
  cout << "\x1b[2J\x1b[H";

  DataBase.AddData(AirTicket(destination, flightNumber, name, date));
}

void DeleteData(AirTicketDataBase &DataBase) {
  string flightNumber, date;
  cout << "Введите номер рейса: " << endl;
  getline(cin, flightNumber);
  cout << "Введите дату вылета: " << endl;
  getline(cin, date);
  cout << "\x1b[2J\x1b[H";

  DataBase.DeleteData(flightNumber, date);
}

void PrintTicket(AirTicketDataBase &DataBase) {
  string flightNumber, date;
  cout << "Введите номер рейса: " << endl;
  getline(cin, flightNumber);
  cout << "Введите дату вылета: " << endl;
  getline(cin, date);

  DataBase.PrintAirTicket(flightNumber, date);
}

int main() {
  cout << "\x1b[2J\x1b[H";
  setlocale(LC_ALL, "ru_RU.UTF-8");
  bool exit = false;
  AirTicketDataBase DataBase = AirTicketDataBase();

  while (!exit) {
    cout << endl << "Меню:" << endl;
    cout << "1. Добавить заявку" << endl;
    cout << "2. Удалить заявку" << endl;
    cout << "3. Вывести все заявки" << endl;
    cout << "4. Вывести заявку по рейсу и дате вылета" << endl;
    cout << "5. Выход" << endl;
    cout << "Выберите действие: ";

    string tmp;
    getline(cin, tmp);
    int action = stoi(tmp);

    switch (action) {
    case 1:
      EnterData(DataBase);
      break;

    case 2:
      DeleteData(DataBase);
      break;

    case 3:
      DataBase.PrintDataBase();
      break;

    case 4:
      PrintTicket(DataBase);
      break;

    case 5:
      exit = true;
      break;

    default:
      cerr << "Некорректное действие!" << endl;
      return 1;
    }
  }

  return 0;
}