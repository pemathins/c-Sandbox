#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

clock_t start, end;
double cpu_time_used; 

//#define const char* FILE_FORMAT = "%d,%s\n"

typedef struct User
{
    char name[35];
    int id;
} User;

int main()
{
    start = clock();
    User pema = {
        .id=8,
        .name="pema"
    };

    char buffer_out[50];
    FILE* out;

    out = fopen("text.dat", "w");
    if(out==0)
    {
        printf("Error opening file try again\n");
        return 1;
    }   

    snprintf(buffer_out, sizeof buffer_out, "%d,%s\n", pema.id,pema.name); 
    
    if(fwrite(buffer_out,sizeof(char),strlen(buffer_out),out) != strlen(buffer_out))
    {
        fclose(out);
        return 1;
    }
    fclose(out);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime Taken to write file : %0.9f",cpu_time_used);

    return 0;
} 