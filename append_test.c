#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include "ourhdr.h"

int main(int argc, char*argv[])
{
	int fd=0;
	off_t currpos=0;
	char buf1[]="vinodvinod";
	char buf2[]="ABCDEFGHIJ";
	if((fd=open("file.hole",O_RDWR|O_CREAT|O_APPEND))<0)
	//if((fd=creat("file.hole",FILE_MODE))<0)
		//perror("creat");
	if((currpos=lseek(fd,10,SEEK_SET))<0);
		perror("seek");
	if(write(fd,buf1,10)!=10)
		perror("first write");
	//if((currpos=lseek(fd,40,SEEK_SET)) == -1)
	//	perror("seek error");
	//if(write(fd,buf2,10)!=10)
	//	perror("2nd write");

	close(fd);
	exit(0);
}
