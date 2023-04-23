#include <iostream>
#include <algorithm>

namespace ca
{   
    static size_t counter=0,counterSet=0;
    template<typename T>
    struct linklist
    {
        private:
            typedef struct node
            {
                T Value;
                node* Nextadd;
            } node;
            
            int nodeSize=0;
            node* startNode;
            node* currentNode=0;

        public:
            linklist()
            {
                counter++;
            }
            
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
                if(nodeSize==0)
                    return startNode->Value;
                    
                node* traverser = nodePointer;

                if(m_count==printTraverser){
                    printTraverser=0;
                    return traverser->Value;
                }

                counter++;
                nodeTraverserPrint(traverser->Nextadd,m_count,counter);

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
                node* createdNode = (node*)malloc(1*sizeof(node));

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
                counter=0;
                return nodeTraverserPrint(startNode,index,counter);
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