#include <iostream>
#include <cstring>
#include <vector>
#include <string>

#define MAXVAL 4500

typedef struct User
{
    int Id;
    char* First_name;
    char* Last_name;
    char* Email;
    char* Gender;
    char* Dob;

    User()
    {
    }

    User(int id,char* first_name,char* last_name,char* email,char* gender,char* dob)
    :Id(id), First_name(first_name), Last_name(last_name), Email(email), Gender(gender), Dob(dob)
    {
    }
    
}User;


int FileLoader(const char*,std::vector<User>&);
void* tree(const char* buffer[]);

int main()
{
    std::vector<User> dataVector;
    dataVector.reserve(1500);
    FileLoader("../testSet.csv",dataVector);
    int value=0,capicity=5;
    
}

int FileLoader(const char* path,std::vector<User>& data)
{
    FILE* file= fopen(path,"r");
    User temp;
    while(!feof(file))
    {
        int id;
        char* first_name;
        char* last_name;
        char* email;
        char* gender;
        char* dob;

        fscanf(file,"%d,%[^,],%[^,],%[^,],%[^,],%[^,]",id,first_name,last_name,email,gender);
        std::cout << "Id : " << id << "Fname : " << first_name << "Lname : " << last_name << "Email : " << email << "Gender : " << gender << "\n";
    }
    fclose(file);
    return 0;
}