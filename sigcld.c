/*************************************************************************
    > File Name: sigcld.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年10月17日 星期五 08时43分13秒
 ************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

static void sig_cld(int);

int main(int argc , char * argv[])
{
	pid_t pid;
	if(signal(SIGCLD , sig_cld) == SIG_ERR)
		perror("signal error");
	if( (pid = fork() ) < 0 )
		perror("fork error");
	else if(pid == 0)
	{
		sleep(2);
		_exit(0);
	}
	pause();
	exit(0);
}
static void sig_cld(int signo)
{
	pid_t pid;
	int status;

	printf("SIGCLD received\n");
	if(signal(SIGCLD , sig_cld) == SIG_ERR )
		perror("signal error");
	if( (pid = wait(&status)) < 0 )
		perror("wait error");
	printf("pid = %d\n",pid);
}
