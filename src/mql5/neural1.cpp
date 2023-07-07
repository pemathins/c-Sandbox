#include <iostream>

class Neuron
{
    private:
    int inputSize=0;
    int outputSize=0;
    int layerSize=0;
    int layerDensitySize=0;
    
    public:
    //input parameters are input,output, layer , layer Density for the neuron.
    Neuron(int p_input,int p_output,int p_layers,int p_layerDensity)
    :inputSize(p_input), outputSize(p_output), layerSize(p_layers), layerDensitySize(p_layerDensity)
    {
        double arrayInput[inputSize];
        double arraylayer[layerSize][layerDensitySize];
        double arrayoutput[outputSize];
    }

};

int main()
{
    Neuron* neuron = new Neuron(5,2,2,32);

}