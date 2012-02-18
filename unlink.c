#include<sys/stat.h>
#include<fcntl.h>
#include "ourhdr.h"

int main()
{
	if((open("vin.txt",O_RDWR))<0)
		printf("open error\n");
	if(unlink("vin.txt")<0)
		printf("unlink error\n");
	printf("unlink successful\n");
	sleep(15);
	printf("done\n");
	exit(0);
}
