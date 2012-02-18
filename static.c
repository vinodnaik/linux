#include<stdio.h>

void foo()
{
	static int a=18;
	a++;
	a++;
	printf("%d\n",a);
}
int main()
{
	foo();
	foo();
}
