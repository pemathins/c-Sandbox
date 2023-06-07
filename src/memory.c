#include<stdlib.h>
#include<stdio.h>
#include<string.h>  

int main()
{
    char splitAt = ' ';
    int count =0;
    char* block;    
     

    void* temp = malloc(5*sizeof(int));

    char* address = (char*)temp;

    const char* name = "Pema Thinley Lepcha";

    memcpy(temp,name,strlen(name));
    for(size_t i=0;i<5*sizeof(int);i++)
    {
        char* r = (char*)(temp+i);
        char x = (char)*r;
        if(x==splitAt)
        {
            memcpy(block,r,count);

            count = 0;
            address = (char*)(temp+i+1);

        }
        printf("Bock : %s\n",block);
        count++;



        printf("%c",x); 
    }
}