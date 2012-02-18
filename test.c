#include<pthread.h>
#include "ourhdr.h"

void * thread1(void *arg)
{
	sleep(2);
	printf("in thread 1\n");
	return ((void *)0);
}

void *thread2(void *arg)
{
	printf("in thread 2\n");
	return ((void *)0);
}

int main()
{
	pthread_t tid1,tid2;
	int err;

	err=pthread_create(&tid1,NULL,thread1,NULL);
	printf("after thread 1\n");
	err=pthread_create(&tid2,NULL,thread2,NULL);
	printf("after theread 2\n");
	sleep(5);
}

