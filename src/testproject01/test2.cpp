#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <string>

#define MAXVAL 4500

typedef struct User
{
    int Id;
    char First_name[50];
    char Last_name[50];
    char Email[50];
    char Gender[15];
    char Dob[15];

    User()
    {
    }

    // User(int id,char first_name[],char last_name[],char email[],char gender[],char dob[])
    // :Id(id), First_name(first_name), Last_name(last_name), Email(email), Gender(gender), Dob(dob)
    // {
    // }
    
}User;


int FileLoader(const char*,std::vector<User>&);
void* tree(const char* buffer[]);

int main(int args,char* argv[])
{
    std::vector<User> dataVector;
    dataVector.reserve(1500);
    FileLoader(argv[1],dataVector);
    int value=0,capicity=5;
    std::cout << "argv[2] : " << argv[2];
    
}

int FileLoader(const char* path,std::vector<User>& data)
{
    
    FILE* file= fopen(path,"r");
    if(file==0)
    {
        std::cerr << "no Data!!\n";
        return 1;
    }
    User temp;
    char buffer[5670];
    memset(buffer,0,5670);
    int count=0;
    int id;
    char first_name[50];
    char last_name[50];
    char email[50];
    char gender[15];
    char dob[15];
    fscanf(file,"%[^\n]",buffer);

    while(!feof(file))
    {
        User temp;
        
        fscanf(file,"%d,%[^,],%[^,],%[^,],%[^,],%[^\n]",&id,first_name,last_name,email,gender,dob);
        temp.Id= id;
        std::memcpy(temp.First_name, first_name,50);
        std::memcpy(temp.Last_name, last_name,50);
        std::memcpy(temp.Email, email,50);
        std::memcpy(temp.Gender, gender,15);
        std::memcpy(temp.Dob, dob,15);
        // printf("id : %d, %s, %s, %s, %s, %s\n",temp.Id,temp.First_name,temp.Last_name,temp.Email,temp.Gender,temp.Dob);
        // {id,first_name,last_name,email,gender,dob}
        data.push_back(temp);
        if(count>1001)
        {
            break;
        }
        count++;
        memset(first_name,0,50);
        memset(last_name,0,50);
        memset(email,0,50);
        memset(gender,0,15);
        memset(dob,0,15);
    }
    std::printf("Line no : %d\n%s",ftell(file),buffer);
    for(auto x : data)
    {
        std::cout << x.Id << " " << x.First_name << " "  << x.Last_name << " "  << x.Email << " "  << x.Gender << " "  << x.Dob << "\n";
    }
    
    
    
    // free(first_name);
    // free(last_name);
    // free(email);
    // free(gender);
    // free(dob);
    // fclose(file);
    return 0;
}