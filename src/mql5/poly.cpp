#include <iostream>

class Base{
    public:
    Base()
    {
        std::cout << "Base Constructor\n" << "\n";
    }
    ~Base()
    {
        std::cout << "Base Distructor\n";
    }
};

class Derived:public Base
{
    public:
    Derived()
    {
        std::cout << "Derived Constructor\n";
    }

    ~Derived()
    {
        std::cout << "Derived distructor\n";
    }
};

int main()
{
    Base* obj = new Derived();
    delete obj;
}
