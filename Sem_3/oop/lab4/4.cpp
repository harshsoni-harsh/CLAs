#include <iostream>
#include <algorithm>

class fraction
{
    public:
        int numerator, denominator;

        fraction(int num, int den)
        {
            numerator = num;
            denominator = den;
        }

        fraction operator +(fraction b)
        {
            fraction c(0,0);
            c.numerator = (numerator * b.denominator) + (b.numerator * denominator);
            c.denominator = (denominator * b.denominator);
            int g = std::__gcd(c.numerator, c.denominator);
            c.numerator /= g;
            c.denominator /= g;
            return c;
        }
        fraction operator -(fraction b)
        {
            fraction c(0,0);
            c.numerator = (numerator * b.denominator) - (b.numerator * denominator);
            c.denominator = (denominator * b.denominator);
            int g = std::__gcd(c.numerator, c.denominator);
            c.numerator /= g;
            c.denominator /= g;
            return c;
        }
        fraction operator *(fraction b)
        {
            fraction c(0,0);
            c.numerator = numerator * b.numerator;
            c.denominator = denominator * b.denominator;
            int g = std::__gcd(c.numerator, c.denominator);
            c.numerator /= g;
            c.denominator /= g;
            return c;
        }
        fraction operator / (fraction b)
        {
            fraction c(0,0);
            c.numerator = numerator * b.denominator;
            c.denominator = denominator * b.numerator;
            int g = std::__gcd(c.numerator, c.denominator);
            c.numerator /= g;
            c.denominator /= g;
            return c;
        }
        void print()
        {
            if (denominator < 0 && numerator < 0)
            {
                numerator *= -1;
                denominator *= -1;
            }
            else if (denominator < 0)
            {
                numerator *= -1;
                denominator *= -1;
            }
            std::cout << numerator << "/" << denominator << std::endl;
        }
};

int main()
{
    fraction a(-1,2);
    fraction b(1,3);
    fraction c = a+b;
    c.print();
}