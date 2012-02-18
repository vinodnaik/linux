#include<sys/wait.h>
#include "ourhdr.h"

void pr_exit(int status)
{
	if(WIFEXITED(status))
		printf("normal termination, exit staus =%d\n",WEXITSTATUS(status));
	else if(WIFSIGNALED(status))
		printf("Abnormal termination, signal number =%d%s\n",WTERMSIG(status),
	#ifdef WCOREDUMP
				WCOREDUMP(status) ? "(core file generated)":"");
#else
	"");
#endif
	else if(WIFSTOPPED(status))
		printf("Child stopped, signal number = %d\n",WSTOPSIG(status));
}

