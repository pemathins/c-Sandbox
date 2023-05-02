#include <stdio.h>
#include <string.h>

double sqrt(int a,int b);

int main()
{
    int a, temp,sum=0;
    printf("Enter a number :");
    scanf("%d",&a);
    temp =a;
    while(temp!=0)
    {
        
        printf("%d\n",temp%10);
        sum += sqrt(temp%10,3);
        temp=temp/10;
    }
    printf("Sum = %d\n",sum);


}

double sqrt(int a,int b)
{
    int sum=1;
    while(b!=0)
    {
        sum *=a;
        b--;
    }
    return (double)sum;
}