#include<sys/stat.h>
#include "ourhdr.h"

void pr_stdio(const char *, FILE *);

int main()
{
	FILE *fp;
	fputs("enter any character\n",stdout);
	if(getchar()==EOF)
		printf("getchar error\n");
	fputs("one line to stderr\n",stderr);

	pr_stdio("stdin",stdin);
	pr_stdio("stdout",stdout);
	pr_stdio("stderr",stderr);

	if((fp=fopen("/etc/motd","r"))==NULL)
		printf("fopen error\n");
	if(getc(fp)==EOF)
		printf("getc error\n");
	pr_stdio("/etc/motd",fp);

	exit(0);
}

void pr_stdio(const char *name, FILE *fp)
{
	printf("stream : %s\t",name);
	if(fp->_IO_file_flags &_IO_UNBUFFERED)
		printf("unbuffered\t");
	else if(fp->_IO_file_flags & _IO_LINE_BUF)
		printf("line buffered\t");
	else
		printf("fully buffered\t");
	printf("buffer size = %d\n",fp->_IO_buf_end-fp->_IO_buf_base);
}
