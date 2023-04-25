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

            int indexCounter=0;
            node* startNode;
            node* currentNode=0;

        public:
            linklist()
            {

            }

            bool nodeTraverser(node* nodePointer,node* currentNode)
            {
                node* m_traverse = nodePointer;
                if(counter==0)
                {
                    m_traverse->Nextadd = 0;
                    return false;
				}
                if(m_traverse->Nextadd==0)
                {
                    m_traverse->Nextadd = currentNode;
				}
                else
                    nodeTraverser(m_traverse->Nextadd,currentNode);
            }

            T nodeTraverserPrint(node* nodePointer,const int& m_count)
            {
                if(counter==0)
                    return nodePointer->Value;
                node* traverser = nodePointer;
                while(traverser->Nextadd!=NULL)
				{
                    traverser = traverser->Nextadd;
					if(indexCounter==m_count)
						break;
					indexCounter++;
				}
				indexCounter=0;
                return traverser->Value;
            }

            int size() const
            {
                return counter;
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
                if(counter==0)
                    startNode = createdNode;

                    // Assign values to the new node created
                createdNode->Value = V;
                createdNode->Nextadd = 0;

               	nodeTraverser(startNode,createdNode);

                    // increment node size

                currentNode = createdNode;
                counter++;
                return true;
            }

            T item(int const& index)
            {
                // node* current = nodeTraverser(startNode,index);

                return nodeTraverserPrint(startNode,index);
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
    //int x = newlist.item(5),
    int y;
   // std::cout << x;
    std::cin >> y;
     for(int i=0;i<y;i++)
     {
         std::cout << "\n" << newlist.item(i);
     }
}
