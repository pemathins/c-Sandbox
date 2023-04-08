#include <iostream>
#include <string>

void cipher(bool mode,std::string&& plaintext, int key)
{
    const char* array = plaintext.c_str();
    size_t x = sizeof(array)/2;

    for(int i=0;i<(int)x;i++){
        // first to mod the value like -> x mod 26
        float n;
        if((int)array[i]>=97&& (int)array[i]<124){
            n = (int)array[i]-96;
            std::cout << "value of n: " << n << " value of array if i : "<< array[i]<<","<< (int)array[i]-96 << std::endl;
        }
        
        if((int)array[i]>=65 && (int)array[i]<91)
        n = (int)array[i]-64;
        
        double y;
        if(mode == true)
        {
            y = (n+key)/26;
        }
        else
        {
            y = (n-key)/26;
        }

        int a  = (y-(int)y)*26;

        if((int)array[i]>=97&& (int)array[i]<124)
        {
            std::cout << (char)(a+96) << " "<< "\n";
        }
        if((int)array[i]>=65 && (int)array[i]<91)
        {
            std::cout << (char)(a+64) << " "<< "\n";
        }
        

    }
}

int main()
{
    std::cout << (int)'a' << std::endl;
    cipher(false,"bB",2);
}