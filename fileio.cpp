#include <iostream>
#include <fstream>

int main() 
{
    std::ofstream out("test");
    if(!out)
    {
        std::cout << "cannt write int test \n";
        return 1;
    }
    
    out << "pema " << 8.5 << std::endl;
    out << "akash " << 7.9 << std::endl;
    out << "mausam " << 8.2 << std::endl;
    out << "roktim " << 7.1 << std::endl;

    out.close();

    std::ifstream in("test");

    if(!in)
    {
        std::cout << "Cannot find the file\n";
        return 1;
    }
    char buffer[35];
    float cgpa;

    in >> buffer >> cgpa;
    std::cout << buffer<< " " << cgpa << "\n";
    in >> buffer >> cgpa;
    std::cout << buffer << " " << cgpa << "\n";
    in >> buffer >> cgpa;
    std::cout << buffer << " " << cgpa << "\n";
    in.close();
    return 0;
}