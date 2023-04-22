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
        
        mutable int counter=0, traverserCounter=0, counterSet=0;
        static int nodeSize=0;
        node* startNode;
        node* currentNode = NULL;

        node* nodeTraverser(node* nodePointer,int m_counter)
        {
            node*m_traverse = nodePointer;
            if(nodeSize == 0)
                counterSet=0;
                return 0;

            if(m_traverse->Nextadd == 0)
                counterSet=0;
                return m_traverse;

            counterSet++;
            nodeTraverser(m_traverse->Nextadd,counterSet);
        }

        T nodeTraverserPrint(node* nodePointer,const int& m_count,int printTraverser)
        {
            if(nodeSize==printTraverser)
                return 0;
                
            node* traverser = nodePointer;

            std::cout << "m_count == "<< m_count << " PrintTrav == " << printTraverser;

            if(m_count==printTraverser){
                printTraverser=0;
                return traverser->Value;
            }

            printTraverser++;
            nodeTraverserPrint(traverser->Nextadd,m_count,printTraverser);
        }

        int size() const
        {
            return nodeSize;
        }

        bool reserve(int&& size)
        {
            return true;
        }
            /* Add function to create node form scratch
            */
        bool add(const T& V)
        {
                // Asign new memory in the buffer
            node* createdNode = (struct node*)malloc(1*sizeof(struct node));

                // First Node initilization
            if(nodeSize == 0)
                startNode = createdNode;

                // Assign values to the new node created
            createdNode->Value = V;
            createdNode->Nextadd = nodeTraverser(startNode,counter);

                // increment node size
            nodeSize++;
            
            currentNode = createdNode;

            return true;
        }

        T item(int const& index)
        {
            // node* current = nodeTraverser(startNode,index);
            int x,printTraverser=0;
             return nodeTraverserPrint(startNode,index,printTraverser);
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
    int x = newlist.item(5);
    std::cout << x;
    // for(int i=0;i<4;i++)
    // {
    //     std::cout << newlist.item(i);
    // }
      
}