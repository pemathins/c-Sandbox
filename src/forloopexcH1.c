#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    char *number[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int a, b,x;
    scanf("%d %d", &a, &b);
    if(b<9)
        x =b;
    else 
        x = 9;
    
        for(int i = a;i<=x;i++){
            printf("%s\n",*(number+i-1));
        }
        
     if(b>9)
     {
        for(int i = 10;i<=b;i++)
        {
            if(i%2==0){
                printf("even\n");
            }
            else {
            {
                printf("odd\n");
            }
            }
        }
     }  
    return 0;
}