#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User
{
	char* name;
	int age;
	unsigned int ID;
} User;

int main()
{
	User arrUser[10];
	User arr;
	User* ptrUserArr = arrUser;
	char* name = (char*)malloc(25*sizeof(char));

	for(int i = 0;i<10;i++)
	{
		printf("Size of User struct is : %d \nEnter user datails name,age,ID\n",sizeof(arrUser));
		scanf("%[^,],%d,%d",name,&arr.age,&arr.ID);
		arrUser[i].name = (char*)malloc(25*sizeof(char));
		strcpy(arrUser[i].name,name);
		arrUser[i].age = arr.age;
		arrUser[i].ID = i+arr.ID+202222000;
	}

	printf("name: %s, age: %d, ID: %u d\n",arrUser[1].name,arrUser[1].age,arrUser[1].ID);
	printf("\n");
	for(int i = 0;i<10;i++)
	{
		printf("%d) name: %s ",i+1,arrUser[i].name);
		printf("  Age :%d ",arrUser[i].age);
		printf("  ID :%u\n",arrUser[i].ID);
	}
	return 0;
}
