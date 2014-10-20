/*************************************************************************
    > File Name: processTest.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年09月16日 星期二 20时44分59秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAXLINE 1024
int main(int argc, char const *argv[])
{
	pid_t pid;
	char buf[MAXLINE];
	int status;

	printf("%% ");
	while( (fgets(buf , MAXLINE , stdin) ) !=NULL )
	{
		if(buf[strlen(buf) -1] == '\n' )
			buf[strlen(buf) -1] = 0;
		if( (pid = fork()) < 0)
		{
			perror("fork error\n");
			return -1;
		}
		else if(pid == 0 )
		{
			execlp(buf ,buf , (char *)0 );
			printf("can't execute :%s ", buf);
			perror("");
			exit(0);
		}
		if( (pid = waitpid(pid , &status , 0)) < 0 )
		{
			perror("waitpid error");
		}
		printf("%% ");
	}
	return 0;
}
