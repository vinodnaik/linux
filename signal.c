#include "ourhdr.h"
#include<signal.h>

void fn(void)
{
	int x=23,n=4;

	sigset_t sig;


	printf("%d\n", (x&1<<(n-1)));

	if(sigprocmask(0,NULL,&sig)<0)
		printf("error\n");

	if(sigismember(&sig,SIGINT))	printf("SIGINT\n");
	if(sigismember(&sig,SIGQUIT))	printf("SIGQUIT\n");
	if(sigismember(&sig,SIGUSR1))	printf("SIGUSR1\n");
	if(sigismember(&sig,SIGALRM))	printf("SIGALRM\n");


}

int main()
{
	fn();
}
