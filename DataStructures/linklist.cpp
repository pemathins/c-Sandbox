#include <iostream>
#include <algorithm>

namespace ca
{   
    template<typename T>
    struct linklist
    {
        struct node
        {
            T* PreviousPtr;
            T Value;
            T* NextPtr;
        };
        
        mutable int counter=0;
        node * startNode null;
        node * last;
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

        bool add(const T& V)
        {
            node.previousPtr = startNode;
            node.value = V;
            node.NextPtr = startNode;
            startNode = node;
            counter++;
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
    ca::linklist<int> newlist;
    newlist.add(45);
    newlist.add(43);
    newlist.add(41);
    newlist.add(42);
    std::cout << newlist.item(0);
}