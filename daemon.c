#include<stdio.h>
#include<fcntl.h>
#include<syslog.h>
#include<sys/resources.h>
#include "ourhdr.h"

void daemonize(const char *cmd)
{
	int i,fd0,fd1,fd2;
	pid_t pid;
	struct rlimit rl;
	struct sigaction sa;
	
	umask(0);


