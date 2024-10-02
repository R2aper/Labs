/*
Вариант 3

Создать класс окружность, член класса - радиус R. Предусмотреть
методы вычисления и вывода сведений о фигуре - площади, длинны окружности.

Создть класс унаследованный от окружности, круглый прямой цилиндр с высотой h.
Добавить в класс метод определения объема фигуры. Перегрузить метод расчета площади 
и вывода сведений о фигуре.

Дано N окружностей и M цилиндров, найти окружность с максимальной площадью и средней объем цилиндра


*/

#include <iostream>
#include <cmath>

using namespace std;

class Circle {
private:
    float R;

public:
    Circle() {
        R = 1.0;
    }

    Circle(float R) {
        this->R = R;
    }


    virtual ~Circle() {}

    float virtual getArea() {
        return M_PI *pow(R, 2);
    }

    float getLength() {
        return 2 * M_PI * R;
    }

    float getR() {
        return this->R;
    }

    void setR(float newR) {
        this->R = newR;
    } 

    void virtual printInfo() {
        cout<< "Radius: " << getR() << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Length: " << getLength() << endl;
    }
};


class Cylinder:public Circle {
private:
    float h;
public:
    Cylinder() {
        h = 1.0;
        setR(1.0);
    }

    Cylinder(float R, float h){
        this->h = h;
        setR(R);
    }


    float getVolume() {
        return getArea() * h;
    }

    float getArea() override {
        return 2 * M_PI * getR() * (getR() + h);
    }

    float getH() {
        return h;
    }

    void setH(float newH) {
        h = newH;
    }
    void printInfo() override {
        cout<<"\nRadius: " << getR() << endl;
        cout << "Height: " << h << endl;
        cout <<"Area: " << getArea() << endl;
        cout << "Volume: " << getVolume() << endl;
    }
};


void EnterDataCircle(Circle *C, int N) {
    cout << "Enter data for Circles\n";
    for (int i = 0; i < N; i++) {
        float R;
        cout << "Enter R: \n";
        cin >> R;
        C[i].setR(R);
        C[i].printInfo();
    }
}

void EnterDataCylinder(Cylinder *Cy, int M) {
    cout << "Enter data for Cylinders\n";
    for (int i = 0; i < M; i++) {
        float R, h;
        cout << "Enter R: \n";
        cin >> R;
        cout << "Enter h: \n";
        cin >> h;
        Cy[i].setR(R);
        Cy[i].setH(h);
        Cy[i].printInfo();
    }
}

void AverageCylinder(Cylinder *Cy, int M) {
    float sum = 0;
    for (int i = 0; i < M; i++) {
        sum += Cy[i].getVolume();
    }
    cout << "Average volume of Cylinders: " << sum / M << endl;
} 

Circle MaxCircle(Circle *C, int N) {
    Circle Max;
    float max = C[0].getArea();
    for (int i = 1; i < N; i++) {
        if (C[i].getArea() > max) {
            max = C[i].getArea();
            Max = C[i];
        }
    }

    return Max;

}


int main() {
    int N, M;
    cout << "Enter N: \n";
    cin >> N;
    cout << endl<< "Enter M: \n";
    cin >> M;

    Circle *C = new Circle[N];
    Cylinder *Cy = new Cylinder[M];

    EnterDataCircle(C, N);
    EnterDataCylinder(Cy, M);

    AverageCylinder(Cy, M);
    Circle Max = MaxCircle(C, N);

    Max.printInfo();


    delete [] C;
    delete [] Cy;

    return 0;
}