#include<stdio.h>
#include<errno.h>
#include "ourhdr.h"

int main()
{
	pid_t pid;
	if((pid=fork())<0)
	{
		printf("fork error\n");
		exit(1);
	}
	if(pid==0)
	{
		if(execl("/usr/bin/ls","/home/vnaik/",(char *)0)<0)
			perror("ls");
			printf("%d\n",errno);
		exit(0);
	}
	sleep(2);
}
