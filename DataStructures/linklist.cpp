#include <iostream>
#include <algorithm>

namespace ca
{   
    template<typename T>
    struct linklist
    {
        struct node
        {
            T Value;
            T* NextPtr;
        };
        
        mutable int counter=0;
        node * startNode = null;
        node * last = null;
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
            node    
            node.value = V;
            node.NextPtr = startNode;
            startNode = node;
            counter++;
            return true;
        }
        T item(int const& index){
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
}