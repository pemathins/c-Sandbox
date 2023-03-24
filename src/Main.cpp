#include <iostream>

struct Test 
{
private:
    int i;
public:
    template<typename T>
    Test(T&& x) 
        :i(std::move(x))
    {
    }
    int fptr = [](int i){ std::cout << i*i; return i*i; }(i);
    
};

int main() {
    Test{42};
}