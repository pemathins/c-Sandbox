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
    User pema = {
        .id=8,
        .name="pema"
    },user2;

    FILE* out;

    out = fopen("textbin.bin", "wb");

    if(out==0)
    {
        printf("File opening Error\n");
        return 1;
    }

    printf("%d",sizeof(pema));
    
    if(fwrite(&pema,sizeof(User),1,out)==0)
    {
        fclose(out);
        return 2;
    }
    fclose(out);


    

    return 0;
} 