#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>

clock_t start, end;
double cpu_time_used;

typedef struct User
{
    int id;
    char* name[35];
} User;

int main()
{
    start = clock();
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
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime Taken to read file : %0.8f",cpu_time_used);
    return 0;
}