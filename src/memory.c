#include<stdlib.h>
#include<stdio.h>
#include<string.h>  

#define charptr char*
#define intptr int*

int* intBuffer(char*, char,int*,int*);
int main()
{
    char buffer[50];
    int* arrlen=(int*)malloc(sizeof(int));
    printf("Enter your arr elements : ");
    scanf("%[^\n]",buffer);
    int* arr = (int*)malloc(50*sizeof(int));
    arr = intBuffer(buffer,' ',arr,arrlen);
    // print the int array
    for(int j=0;j<*arrlen;j++)
        printf("%d) -> %d\n",j,arr[j]);
    free(arr);
    free(arrlen);
}

//it takes a buffer (string value) and conversts int* arrays 
//parameters buffer string vaue,splitAt char to split at, array an stack allocated array of int pointers and arrlen the length of the array also stack int pointer 
int* intBuffer(char* buffer, char splitAt,int* array,int* arrlen)
{
    // char splitAt = 32;
    size_t count =0,t=0;
    charptr block[10];    
    charptr rx;
    void* temp = malloc(strlen(buffer)*sizeof(char));
    char* address = (char*)temp;
    rx = address;
    // const char* buffer,name = "34 35 56 23 67 89";

    memcpy(temp,buffer,strlen(buffer));
    //printf("Buffer is : %s",buffer);
    for(size_t i=0;i<strlen(buffer);i++)
    {
        char* r = (char*)(temp+i);
        char x = (char)*r;
        if(x==splitAt || i==strlen(buffer)-1)
        {
            memcpy(block,rx,count);
            count = 0;
            rx = (char*)(temp+i+1);
            array[t] = atoi((const char*)block);
            t++;

        }
        //printf("Bock : %s\n",block);
        memset(block,0,10);
        
        count++;
        //printf("%c",x); 
    }
    *arrlen = t;
    free(temp);
    return array;
}