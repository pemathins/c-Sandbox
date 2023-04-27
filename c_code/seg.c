#include <stdio.h>
#include<stdlib.h>

void foo()
{
	int* p = NULL;
	//p = malloc(sizeof(int));
	*p = 42;
}

void bar()
{
	foo();
}

int main()
{
	bar();
	return 0;
}
