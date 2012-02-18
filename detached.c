#include<stdio.h>
#include<pthread.h>

void * thr(void *arg)
{
	pthread_t tid;
	tid=pthread_self();
	printf("%u\n",(unsigned int)tid);
}

int main()
{
	pthread_t tid;
	int err;
	void *arg;
	pthread_attr_t attr;

	err=pthread_attr_init(&attr);
	if(err !=0)
		return ;
	err=pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	if(err==0)
		err=pthread_create(&tid,&attr,thr,NULL);
	pthread_attr_destroy(&attr);
	sleep(1);

	return;
}

	
