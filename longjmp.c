/*************************************************************************
    > File Name: longjmp.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年10月17日 星期五 10时48分33秒
 ************************************************************************/

#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXLINE 1024

static void sig_alrm(int);
static jmp_buf env_alrm;

int main(int argc ,char * argv[])
{
	int n;
	char line[MAXLINE];

	if(signal(SIGALRM , sig_alrm) == SIG_ERR )
	{
		perror("signal(SIGALRM) error ");
		return -1;
	}
	if(setjmp(env_alrm) != 0 )
	{
		perror("read timeout");
		return -1;
	}
	alarm(10);
	if( (n = read(STDIN_FILENO , line , MAXLINE)) < 0 )
	{
		perror("read error");
		return -1;
	}
	alarm(0);
	write(STDOUT_FILENO , line , n);
	exit(0);
}

static void sig_alrm(int signo)
{
	longjmp(env_alrm , 1);
}
