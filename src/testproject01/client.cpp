#include <iostream>
#include <string>

void cipher(int mode,std::string&& plaintext, int key)
{
    const char* array = plaintext.c_str();
    for(int i=0;i<(int)sizeof(array);i++){
        std::cout << (int)array[i] << ",";
    }
}

int main()
{
    cipher(1,"Pema",2);
}