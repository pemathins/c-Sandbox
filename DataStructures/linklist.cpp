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
            node * Nextadd;
        };
        
        mutable int counter=0;
        node * startNode;
        node * first;
        node * last;
        int capicity() const
        {
            return counter;
        }

        bool reserve(int&& size)
        {
            return true;
        }

        bool add(const T& V)
        {
            first = (struct node*)malloc(1*sizeof(struct node));
            last = (struct node*)malloc(1*sizeof(struct node));
            first->Value = V;
            first->Nextadd = last;
            if(counter == 0)
                startNode = first;
            counter++;
            return true;
        }
        T item(int const& index)
        {
        }
        ~linklist()
        {
            /*free the struct

            */
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