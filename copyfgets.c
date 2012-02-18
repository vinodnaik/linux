#include<sys/stat.h>
#include "ourhdr.h"

#define max 10

int main()
{
	char buf[max];
	setvbuf(stdin,NULL,_IONBF);
	perror("setbuf");
	while(fgets(buf,max,stdin)!=NULL)
		if(fputs(buf,stdout)==EOF)
			printf("o/p error\n");

	if(ferror(stdin))
		printf("i/p error\n");

	exit(0);
}	
