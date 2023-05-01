#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>
//#define const char* FILE_FORMAT = "%d,%s\n"

     
     clock_t start, end;
     double cpu_time_used;

typedef struct User
{
    int id;
    char name[35];
    
} User;

int main()
{
    start = clock();
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
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime Taken to read file in binary : %0.8f",cpu_time_used);
    return 0;
} 