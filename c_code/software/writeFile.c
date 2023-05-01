#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

//#define const char* FILE_FORMAT = "%d,%s\n"

typedef struct User
{
    char name[35];
    int id;
} User;

int main()
{
    User pema = {
        .id=8,
        .name="pema"
    };

    char buffer_out[50],buffer_in[50];
    FILE* in;
    FILE* out;

    out = fopen("text.dat", "a");
    if(out==0)
    {
        printf("Error opening file try again\n");
        return 1;
    }   

    snprintf(buffer_out, sizeof buffer_out, "%d,%s\n", pema.id,pema.name); 

    int writerValue = fwrite(buffer_out,sizeof(char),strlen(buffer_out),out);
    fclose(out);
    if(writerValue != strlen(buffer_out))
    {
        return 1;
    }

    return 0;
} 