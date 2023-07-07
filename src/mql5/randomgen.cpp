#include <cstdlib>
#include <iostream>
#include <time.h>

#define WEIGTH "%f"
#define SEP ","
#define BIAS "%f"
#define inputlayer "%f,%f,%f,%f,%f,%f\n"

typedef struct WBinputlayer
{
    float w1;
    float w2;
    float w3;
    float w4;
    float w5;
    float b;
};


float gen()
{
    
    float divident= (float)(rand()%219);
    float divisor = (float)(rand()%789);
    return divident/divisor;

}

void generateRandoms(int ilayer)
{
    srand(time(0));
    int inputlayerSize = ilayer;
    int outputSize;
    int LayerSize;
    int LayerDesistySize;
    int interiorNodes = LayerSize* LayerDesistySize;

    FILE* file = fopen("./weightbiases.dat","w");


    for(int i =0;i<inputlayerSize;i++)
    {
        fprintf(file,inputlayer,gen(),gen(),gen(),gen(),gen(),gen());
    }
}
int main()
{
    
    
    generateRandoms(5);

}