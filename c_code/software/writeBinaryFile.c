#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>

clock_t start, end;
double cpu_time_used;

//#define const char* FILE_FORMAT = "%d,%s\n"

typedef struct User
{
    int id;
    char name[35];
    
} User;

int main()
{
    start = clock();
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
    
    if(fwrite(&pema,sizeof(User),1,out)==0)
    {
        fclose(out);
        return 2;
    }
    fclose(out);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime Taken to write file in binary : %0.9f",cpu_time_used);
    

    return 0;
} 