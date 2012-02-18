#include<sys/types.h>
#include<fcntl.h>
#include "ourhdr.h"

int main(int argc, char *argv[])
{
	int accmode,val;

	if((val=fcntl(atoi(argv[1]),F_GETFL,0)) <0)
		printf("fcntl error\n");

	accmode=val&O_ACCMODE;

	if(accmode==O_RDONLY)	printf("read only\n");
	else if(accmode==O_WRONLY)	printf("write only\n");
	else if(accmode==O_RDWR)	printf("read write\n");
	else	printf("unknown access mode\n");

	if(val & O_APPEND)	printf("append\n");
	if(val & O_NONBLOCK)	printf("non blocking\n");
	
#if !defined(_POSIX_SOURCE) && defined(O_SYNC)
	if(val&O_SYNC)	printf("synchronous writes\n");
#endif
	putchar('\n');
	exit(0);
}

