#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pemasheader.h"

int main()
{
 
    char name[10] = "HeleH"; 
    int len = strlen(name)+1;
    char* str = malloc(10*sizeof(char));
    strncpy(str,name,sizeof(name));
    printf("%s\nname : %s\n",str,name);
    char rev[strlen(str)];
    for(int i =strlen(str)-1,x=0;i>0,x<strlen(str);i--,x++)
    {
        rev[x] =str[i];
        printf("%c\n",str[i]);
    }
    printf("reverser : %s\n",rev);
    if(palandromic(name,rev)==0)
        printf("String is palandromic.\n");
    else    
        printf("String is Not palandromic.\n");
    return 0;
}
 
