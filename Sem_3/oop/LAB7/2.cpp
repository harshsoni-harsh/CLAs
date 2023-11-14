#include <bits/stdc++.h>

using namespace std;
class Shape {
    public:
        virtual float area(int a) {
            cout << "I can calculate area" << endl;
            return 0;
        }
    protected:
        int a;
};
class Square : public Shape {
    public:
        Square(int side) {
            a = side;
        }
        float area() {
            return a*a;
        }
};
class Circle : public Shape {
    public:
        Circle(int radius)
        {
            a = radius;
        }
        float area() {
            return 3.14*a*a;
        }
};
class equilateralTriangle : public Shape {
    public:
        equilateralTriangle(int side) {
            a = side;
        }
        float area() {
            return sqrt(3.0/4.0)*a*a;
        }
};

int main() {
    cout << "Enter a number from the below options to get the area of" << endl;
    cout << "1. Square\n2. Circle\n3. Equilateral Triangle\n";
    int x, a;
    cin >> x;
    switch(x) {
        case 1: {
            cout << "\nEnter the side length: ";
            cin >> a;
            cout << endl;
            Square s(a);
            cout << "Area: " << s.area();
        }
            break;
        case 2: {
            cout << "\nEnter the radius: ";
            cin >> a;
            cout << endl;
            Circle s(a);
            cout << "Area: " << s.area();
        }
            break;
        case 3: {
            cout << "\nEnter the side length: ";
            cin >> a;
            cout << endl;
            equilateralTriangle s(a);
            cout << "Area: " << s.area();
        }
            break;
        default:
            cout << "Unknown shape" << endl;
    } cout << endl;
    return 0;

}