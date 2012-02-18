#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include "ourhdr.h"

int main(int argc, char *argv[])
{
	char *ptr;
	int i;
	struct stat buf;

	for(i=1;i<argc;i++)
	{
		printf("%s:",argv[i]);
		if((lstat(argv[i],&buf))<0)
		{
			perror("lstat error\n");
			continue;
		}
		else if(S_ISREG(buf.st_mode))
			ptr="regular";
		else if(S_ISDIR(buf.st_mode))
			ptr="directory";
		else if(S_ISCHR(buf.st_mode))
			ptr="character device";
		else if(S_ISBLK(buf.st_mode))
			ptr="block";
		else if(S_ISFIFO(buf.st_mode))
			ptr="Fifo";
		else if(S_ISLNK(buf.st_mode))
			ptr="link";
		else if(S_ISSOCK(buf.st_mode))
			ptr="socket";
		else
			ptr="unknown";
		printf("%s\n",ptr);
	}

	exit(0);
}
