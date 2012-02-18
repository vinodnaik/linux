#include<sys/stat.h>
#include "ourhdr.h"

int glob=6;
char buf[]="this is s string\n";

int main()
{
	int var;
	pid_t pid;
	
	var=88;
	if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
		printf("write error\n");
	printf("Before fork\n");

	if((pid=vfork()) <0)
	{
		printf("Fork error\n");
		exit(0);
	}
	else if(pid==0)
	{
		var++;
		glob++;
		_exit(0);
	}

	printf("pid=%d\tvar=%d\tglob=%d\n",getpid(),var,glob);

	exit(0);
}
