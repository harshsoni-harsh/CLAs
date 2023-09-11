#include <iostream>

class Dogs;
class Pigs;
class Horses;
class Dogs
{
    private:
        int count = 0;
    public:
        void add()
        {
            count++;
        }
        void remove()
        {
            count--;
        }
        friend void animals(Dogs& d, Pigs& p, Horses& h);
};

class Pigs
{
    private:
        int count = 0;
    public:
        void add()
        {
            count++;
        }
        void remove()
        {
            count--;
        }
        friend void animals(Dogs& d, Pigs& p, Horses& h);
};

class Horses
{
    private:
        int count = 0;
    public:
        void add()
        {
            count++;
        }
        void remove()
        {
            count--;
        }
        friend void animals(Dogs& d, Pigs& p, Horses& h);
};
void animals(Dogs& d, Pigs& p, Horses& h)
{
    std::cout << "Total animals: "<< d.count + p.count + h.count << std::endl;
};

int main()
{
    Dogs d;
    Pigs p;
    Horses h;
    d.add(), p.add(), h.add();
    d.add(), p.remove();
    d.add();
    animals (d,p,h);
}