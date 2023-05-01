#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct User
{
    int id;
    char* name[35];
} User;

int main()
{
    User user;
    char buffer_in[50];
    FILE* in;

    in = fopen("text.dat", "r");

    if(fgets(buffer_in, sizeof buffer_in,in)==0)
    {
        fclose(in);
        return 1;
    }
    fclose(in);

    sscanf(buffer_in,"%d,%[^\n]",&user.id,user.name);
    printf("name = %s, id = %d",user.name,user.id);

    return 0;
}