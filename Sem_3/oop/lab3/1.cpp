#include <iostream>

using namespace std;
class Area{
    private:
    int a, b;

    public:
    void setDim()
    {
        cout << "Enter a: ";
        cin >> a;
        cout << "Enter b: ";
        cin >> b;
    }
    void getArea()
    {
        cout << "Area with given dimensions is " << a*b<< endl;
    }
};

int main()
{
    Area *ar = new Area();
    ar->setDim();
    ar->getArea();
}