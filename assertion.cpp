#include <iostream>
#include <cassert>

struct Add {
constexpr int add(int a, int b) {
    return a+b;
}

};
int main() {
    int test1, test2;
    std::cin >> test1 >> test2;
    Add x;
    static_assert(x.add(12 ,21)<=45 && "Case fale in runtime");
    assert(x.add(test1,test2)<=45 && "Didnt make through"); 
}