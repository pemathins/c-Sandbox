#include <iostream>

struct Test 
{
private:
    int i;
    template<typename... T,typename N>
    void printValue(T... t) { std::cout << std::get<N>(t...) <<"\n";}
public:
    template<typename ... T>
    Test(T&& ... x)
    {
        printValue(x...);
    }
    int fptr = [](int i){ std::cout << i*i; return i*i; }(i);
    
};

int main() {
    Test{32 ,56 ,23.2f};
}