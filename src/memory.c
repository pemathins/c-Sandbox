#include<stdlib.h>
#include<stdio.h>
#include<string.h>  

#define charptr char*
int main()
{
    char splitAt = 32;
    size_t count =0;
    charptr block[10];    
    charptr rx;

    void* temp = malloc(5*sizeof(int));

    char* address = (char*)temp;
    rx = address;
    const char* name = "34 35 56 23 67 89";

    memcpy(temp,name,strlen(name));
    for(size_t i=0;i<strlen(name);i++)
    {
        char* r = (char*)(temp+i);
        char x = (char)*r;
        if(x==splitAt || i==strlen(name)-1)
        {
            memcpy(block,rx,count);
            count = 0;
            rx = (char*)(temp+i+1);

        }
        printf("Bock : %s\n",block);
        memset(block,0,10);
        count++;

        printf("%c",x); 
    }
}