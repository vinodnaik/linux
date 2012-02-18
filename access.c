#include<sys/stat.h>
#include<sys/fcntl.h>
#include "ourhdr.h"

int main(int argc, char *argv[])
{
	if((access(argv[1],R_OK))<0)
		printf("read error\n");
	else
		printf("read ok\n");
	if((open(argv[1],O_RDONLY))<0)
		printf("open error for %s\n",argv[1]);
	else
		printf("open for reading ok\n");
	return 0;
}

