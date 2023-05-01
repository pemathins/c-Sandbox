#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

//#define const char* FILE_FORMAT = "%d,%s\n"

typedef struct User
{
    int id;
    char name[35];
    
} User;

int main()
{
    User user;


    FILE* in;

    in = fopen("textbin.bin", "rb");

    if(in==0)
    {
        printf("File opening Error\n");
        return 1;
    }

    
    if(fread(&user, sizeof(User), 1, in)==0)
    {
        fclose(in);
        return 2;
    }

    

    printf("User name: %s, Id: %d",user.name,user.id);
    fclose(in);

    return 0;
} 