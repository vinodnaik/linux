#include<stdio.h>
#include<pthread.h>
#include "ourhdr.h"

void printids(const char *s)
{
	pid_t pid;
	pthread_t tid;

	pid=getpid();
	tid=pthread_self();

	printf("%s pid=%u tid=%u(0x%x)\n",s,(unsigned int)pid,(unsigned int)tid);
}

void * thr_fn(void * arg)
{
	printf("in thread\n");
	//sleep(3);
	printids("new thread");
	return ((void *)0);
}

int main()
{
	pthread_t ntid;

	int err;

	err=pthread_create(&ntid,NULL,thr_fn,NULL);
	if(err !=0)
		printf("thread creation error\n");

	printids("main thread");
	sleep(2);
	exit(0);
}

