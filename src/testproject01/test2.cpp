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
    char buffer[567];
    memset(buffer,0,567);
    fscanf(file,"%[^\n]",buffer);

    int id;
    char* first_name = (char*)malloc(sizeof(char)*50);;
    char* last_name = (char*)malloc(sizeof(char)*50);
    char* email = (char*)malloc(sizeof(char)*50);
    char* gender = (char*)malloc(sizeof(char)*9);
    char* dob = (char*)malloc(sizeof(char)*15);

    while(!feof(file))
    {
        
        char newline  = fgetc(file);
        fscanf(file,"%d,%[^,],%[^,],%[^,],%[^,],%[^\n]",&id,first_name,last_name,email,gender,dob);
        temp.Id = id;
        temp.First_name = first_name;
        temp.Last_name = last_name;
        temp.Email = email;
        temp.Gender = gender;
        temp.Dob = dob;
        printf("id : %d, %s, %s, %s, %s, %s\n",temp.Id,temp.First_name,temp.Last_name,temp.Email,temp.Gender,temp.Dob);
        data.emplace_back(temp.Id,temp.First_name,temp.Last_name,temp.Email,temp.Gender,temp.Dob);
        
    }
    printf("Line no : %d\n",ftell(file));
    
    // for(User x : data)
    //     printf("id : %d, %s, %s, %s, %s, %s\n",x.Id,x.First_name,x.Last_name,x.Email,x.Gender,x.Dob);

    free(first_name);
    free(last_name);
    free(email);
    free(gender);
    free(dob);
    fclose(file);
    return 0;
}