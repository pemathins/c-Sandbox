#include <iostream>
#include <algorithm>

namespace ca
{   
    template<typename T>
    struct arraylist
    {
        int max_size = 50;
        int pointer = -1;
        mutable int counter;
        int capicity() const
        {
            return max_size;
        }
        bool reserve(int&& size)
        {
            if(max_size < size)
                T newlist[size] = new t[size];
                return true;
            else 
                return false;
        }
        T array[max_size];

        bool add(const T& V)
        {
            pointer++;
            arraylist[pointer] = V;
            return true;
        }
        T item(int const& index){
            if(index <= max_size AND index > 0)
                return arraylist[index];
            else
                throw "error";
        }

    };
}

int main() 
{
    ca::arraylist<int> newlist;
    newlist.add(45);
    newlist.add(43);
    newlist.add(41);
    newlist.add(42);
    std::cout << newlist.item(0);
}