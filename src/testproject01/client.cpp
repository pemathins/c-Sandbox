#include <iostream>
#include <string>

void cipher(int mode,std::string&& plaintext, int key)
{
    const char* array = plaintext.c_str();
    size_t x = sizeof(array)/2;

    for(int i=0;i<(int)x;i++){
        // first to mod the value like -> x mod 26
        int n = (int)array[i];
        float y = (n+key)/26;

        int a  = (y-(int)y)*26;
        std::cout << "foat : " << y << " " << (int)array[i] << (int)a << ",";

    }
}

int main()
{
    cipher(1,"neso",2);
}