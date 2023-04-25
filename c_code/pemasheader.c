#include <stdlib.h>
#include <string.h>

int palandromic(char str1[],char str2[])
{
    int count=0;
    for(int i = 0; i<strlen(str1)-1;i++)
    {
        if(str1[i]!=str2[i])
            count++; 
    }
    if(count>0)
        return -1;
    else
        return 0;
}