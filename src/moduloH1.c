#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    char n[5]="\0\0\0\0\0";
    int sum=0;
    char* x = (char*)malloc(sizeof(char));
    scanf("%s", n);
    printf("%s",n);
    for(int i = 0;i<strlen(n);i++)
    {
        sprintf(x,"%s",n+i);
        printf("%d) %s\n",i+1,x);
        sum += atoi(x);
    }
    printf("\n%d\n",sum);
    return 0;
}