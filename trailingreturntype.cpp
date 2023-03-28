#include <iostream>
#include <vector>
#include <algorithm>

struct Test {
    size_t x;
    bool t2;
    int32_t x2;
    std::vector<int> function(std::vector<int>& vec1) {
        
        return std::sort(vec1.begin(), vec1.end());
    }
};

int main() {
    std::vector<int> vec1 = {12,33,227,44,12,134,121};
    Test test;
    std::vector<int> vec2 = test.function(vec1);
    for(auto x: vec2)
        std::cout << x << " , ";
}