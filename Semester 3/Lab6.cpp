/*

Вариант - 3

TODO:

!Составить программу, которая:
* Обеспечивает первоночальный ввод целых чисел и формирует из них стек
* Затем переписывает во второй стек четные числа, а в третий - нечетные
* Все стеки должны быть показаны на экране

*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

template <typename T> void PrintStack(stack<T> stack) {
  while (!stack.empty()) {
    cout << stack.top() << endl;
    stack.pop();
  }
}

int main() {
  setlocale(LC_ALL, "ru_RU.UTF-8");
  stack<int> numbers, odd, even;
  int size = 0, input = 0;

  cout << "Введите количество чисел:" << endl;
  cin >> size;

  for (int i = 0; i < size; i++) {
    cin >> input;
    numbers.push(input);
  }

  if (numbers.empty()) {
    cerr << "Стек пуст!" << endl;
    return 1;
  }

  cout << "Все числа:" << endl;
  PrintStack(numbers);

  for (int i = 0; i < size; i++) {
    if (numbers.top() % 2 == 0)
      even.push(numbers.top());
    else
      odd.push(numbers.top());

    numbers.pop();
  }

  cout << "Четные:" << endl;
  PrintStack(even);
  cout << "Нечетные:" << endl;
  PrintStack(odd);

  return 0;
}