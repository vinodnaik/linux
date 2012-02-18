#include<sys/wait.h>
#include<pwd.h>
#include "ourhdr.h"

static void my_alarm(int signo)
{
	struct passwd *rootptr;
	printf("In signal handler\n");
	if((rootptr=getpwnam("root"))==NULL)
		printf("getpwnam(root) error\n");
	alarm(1);
}

int main()
{
	struct passwd *ptr;

	signal(SIGALRM,my_alarm);

	alarm(1);
	for(;;)
	{
		if((ptr=getpwnam("vinod"))==NULL)
			printf("getpwnam(vinod) error\n");
		if(strcmp(ptr->pw_name,"vinod")!=0)
			printf("return name corrupted, pw name=%s\n",ptr->pw_name);
	}

}
