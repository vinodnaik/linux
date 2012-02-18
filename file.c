#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include "ourhdr.h"

int main(int argc, char *argv[])
{
	struct stat fp;
	if(stat("/home/vinod/linux/copy.c",&fp)<0)
		perror(argv[0]);
	else
	{
		printf("inode no %d\n",fp.st_ino);
		printf("size = %d\n",fp.st_size);
	}
	exit(0);
}

