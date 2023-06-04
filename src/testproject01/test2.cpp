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
    char First_name[20];
    char Last_name[15];
    char Email[19];
    char Gender[8];
    char Dob[10];

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

int main()
{
    std::vector<User> dataVector;
    dataVector.reserve(1500);
    FileLoader("testSet.csv",dataVector);
    int value=0,capicity=5;
    
}

int FileLoader(const char* path,std::vector<User>& data)
{
    FILE* file= fopen("/home/thinley/Documents/cpp-programs/c-Sandbox/src/testproject01/testSet.csv","r");
    User temp;
    char buffer[5670];
    memset(buffer,0,5670);
    int counter =0;
    int id;
    char* first_name = (char*)malloc(sizeof(char)*50);;
    char* last_name = (char*)malloc(sizeof(char)*50);
    char* email = (char*)malloc(sizeof(char)*50);
    char* gender = (char*)malloc(sizeof(char)*9);
    char* dob = (char*)malloc(sizeof(char)*15);

    while(!feof(file))
    {
        User temp;
        std::fscanf(file,"%d,%[^,],%[^,],%[^,],%[^,],%[^\n]",temp.Id,temp.First_name,temp.Last_name,temp.Email,temp.Gender,temp.Dob);
        // temp.Id, id;
        // std::memcpy(temp.First_name, first_name,20);
        // std::memcpy(temp.Last_name, last_name,15);
        // std::memcpy(temp.Email, email,19);
        // std::memcpy(temp.Gender, gender,8);
        // std::memcpy(temp.Dob, dob,10);
        std::printf("id : %d, %s, %s, %s, %s, %s\n",temp.Id,temp.First_name,temp.Last_name,temp.Email,temp.Gender,temp.Dob);
        //{id,first_name,last_name,email,gender,dob}
        data.push_back(temp);
        if(counter<1001)
            break;
        counter++;
    }
    std::printf("Line no : %d\n",ftell(file));
    
    for(User x : data)
        printf("id : %d, %s, %s, %s, %s, %s\n",x.Id,x.First_name,x.Last_name,x.Email,x.Gender,x.Dob);

    free(first_name);
    free(last_name);
    free(email);
    free(gender);
    free(dob);
    fclose(file);
    return 0;
}