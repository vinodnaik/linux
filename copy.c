#include<sys/stat.h>
#include<sys/types.h>
#include "ourhdr.h"

#define BUF 8192

int main()
{
	int n;
	char buf[BUF];

	while((n=read(STDIN_FILENO,buf,BUF))>0)
		if(write(STDOUT_FILENO,buf,n) != n)
			perror("write");

	if(n<0)
		perror("read");

	exit(0);
}

