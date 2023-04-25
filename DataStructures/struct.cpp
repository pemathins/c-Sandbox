#include <iostream>
#include <algorithm>
typedef struct node 
{
    int value;
    node* nxtptr;
} node;

namespace ca 
{
    static int listCounter=0;
    struct list
    {    
         list()
        {
            ++listCounter; 
        }
         auto counterfunc() -> int
        {
			std::cout << sizeof(node);
            return listCounter;
        }

    };

}

int main()
{
    std::cout << ca::listCounter;
    ca::list X;
    ca::list y;
    ca::list Z;
    std::cout << Z.counterfunc();
}
