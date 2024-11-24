/*

Вариант -3

TODO:

В вычислительной системе задания на выполнение выстраиваются в очередь

!Для каждого задания содержатся следующие сведения:
* Имя задания;
* Время постановки в очередь (часы: минуты);
* Количество требуемой памяти.

!Составить программу, которая обеспечивает:
* Начальное формирование очереди заданий;
* Вывод очереди на экран;
* Удаление заданий, объем памяти для которых больше заданной;

*/

#include <ctime>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Time {
private:
  int hours;
  int minutes;

public:
  Time() : hours(0), minutes(0) {}

  Time(int hours, int minutes) {
    this->hours = hours;
    this->minutes = minutes;
  }

  const string getTime() const { return (to_string(hours) + ":" + to_string(minutes) + " ч."); }

  void setTime(int hours, int minutes) {
    this->hours = hours;
    this->minutes = minutes;
  }

  friend ostream &operator<<(ostream &out, const Time &data) {
    out << data.getTime();
    return out;
  }
};

class Task {
private:
  string name;
  Time TimeToComplete;
  float memory;

public:
  Task() : name(""), TimeToComplete(Time(0, 0)), memory(0.0) {}

  Task(const string &name, Time TimeToComplete, float memory) {
    this->name = name;
    this->TimeToComplete = TimeToComplete;
    this->memory = memory;
  }
  const string &getName() { return name; }
  Time getTimeToComplete() { return TimeToComplete; }
  float getMemory() { return memory; }

  void setName(const string &name) { this->name = name; }
  void setTimeToComplete(Time TimeToComplete) { this->TimeToComplete = TimeToComplete; }
  void setMemory(float memory) { this->memory = memory; }

  friend ostream &operator<<(ostream &out, const Task &data) {
    out << string(55, '-') << endl;
    out << "Назвние задания: " << endl << data.name << endl;
    out << "Время постановки в очередь в часах: " << endl << data.TimeToComplete << endl;
    out << "Количество требуемой памяти: " << endl << data.memory << endl;
    out << string(55, '-') << endl;
    return out;
  }
};

template <typename T> void PrintQueue(queue<T> queue) {
  while (!queue.empty()) {
    cout << queue.front() << endl;
    queue.pop();
  }
}

int main() {
  setlocale(LC_ALL, "ru_RU.UTF-8");
  srand(time(0));

  const string names[] = {"Задание 1", "Задание 2", "Задание 3", "Задание 4", "Задание 5"};
  queue<Task> tasks, tmp;
  int size = 0;

  cout << "Введите количество заданий: " << endl;
  cin >> size;

  for (int i = 0; i < size; i++)
    tasks.push(Task(names[rand() % 5], Time(rand() % 24, rand() % 60), rand() % 5000 + 1));

  if (tasks.empty()) {
    cerr << "Очередь пуста!" << endl;
    return 1;
  }

  cout << "Очередь заданий: " << endl;
  PrintQueue(tasks);

  cout << "Введите количество требуемой памяти: " << endl;
  float memory;
  cin >> memory;

  for (int i = 0; i < tasks.size(); i++) {
    if (tasks.front().getMemory() <= memory) {
      tmp.push(tasks.front());
      tasks.pop();
    }
  }

  tasks = tmp;

  if (tasks.empty()) {
    cerr << "Очередь пуста!" << endl;
    return 1;
  }

  cout << "Очередь без заданий с большим объемом памяти чем " << memory << ": " << endl;
  PrintQueue(tasks);

  return 0;
}
