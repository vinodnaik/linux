#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include "ourhdr.h"

int main()
{
	if(lseek(STDIN_FILENO,0,SEEK_CUR)==-1)
		printf("cannot seek\n");
	else
		printf("seek ok\n");
	exit(0);
}

