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
            node* Nextadd;
        };
        
        mutable int counter=0,traverserCounter=0,counterSet=0;
        node* startNode;
        node* first;
        node* currentNode = NULL;

        node* nodeTraverser(node* nodePointer,int m_counter)
        {
            node* traverse = nodePointer;
            std::cout << traverse->Value << "\n";
            if(traverse == first)
                return 0;
            if(traverse->Nextadd == (std::nullptr_t)nullptr)
                return traverse;
            counterSet++;
            nodeTraverser(traverse->Nextadd,counterSet);
        }

        int nodeTraverserPrint(node* nodePointer,int m_count)
        {
            if(m_count == counterSet)
                return 0;
            node* traverse = nodePointer;
            std::cout << traverse->Value << "\n";
            
            counterSet++;
            nodeTraverserPrint(traverse->Nextadd,m_count);
        }

        int size() const
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
            if(counter == 0)
                startNode = first;

            first->Value = V;
            first->Nextadd = nodeTraverser(startNode,counter);
            counter++;
            currentNode = first;
            std::cout << "my Address is : " << first << " | counter : " << counter << "\n";
            std::cout << "value : " << first->Value << " | nextaddress : " << first->Nextadd << "\n";
            return true;
        }

        void item(int const& index)
        {
            // node* current = nodeTraverser(startNode,index);
            nodeTraverserPrint(startNode,index);
            counterSet=0;
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
    newlist.add(41);
    newlist.add(42);
    newlist.add(43);
    newlist.add(44);
    newlist.add(45);
    newlist.add(46);
    
    newlist.item(5);
    // for(int i=0;i<4;i++)
    // {
    //     std::cout << newlist.item(i);
    // }
      
}