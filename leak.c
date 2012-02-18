#include "ourhdr.h"
#include<stdlib.h>
#include<stdio.h>
#include "memwatch.h"

int main()
{
	char *p1;
	char *p2;

	p1=malloc(512);
	p2=malloc(512);

	p2=p1;

	free(p2);
	free(p1);
}

