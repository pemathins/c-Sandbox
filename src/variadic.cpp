#include <iostream>

struct Test 
{
    template<typename first>
    auto printValue(first f)
    { 
        std::cout << f <<"\n";
    }
    template<typename first,typename... T>
    auto printValue(first f,T... t)
    { 
        std::cout << f <<"\n";
        printValue(t...);
    }

    template<typename... T>
    Test(T&&... t)
    {
        printValue(t...);
    }    
};

int main() {
    Test{32, 56, 45.4f, 23};
}