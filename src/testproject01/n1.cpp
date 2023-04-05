#include <iostream>
#include <fstream>
#include <string>

int main() 
{
    int a,n =0;
    std::string fname, mnanme, lname, password, password2, code, age, user, word1, word2;
    std::cout << "\t\t  System Managment Security\n";
    std::cout << "_______________________________________________\n";
    std::cout << "|            1. Register                      |\n";
    std::cout << "|            2. Login                         |\n";
    std::cout << "|            1. Cnhange Password              |\n";
    std::cout << "|            1. End Program                   |\n";
    std::cout << "|_____________________________________________|\n";

    do {
        std::cout << "Enter your choice :-";
        std::cin >> a;
    }while(a!=4); 
}