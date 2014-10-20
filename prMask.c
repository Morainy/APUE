/*************************************************************************
    > File Name: prMask.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年10月18日 星期六 09时35分24秒
 ************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <errno.h>

void pr_mask(const char * str)
{
	sigset_t sigset;
	int errno_save;

	errno_save = errno;
	if(sigprocmask(0 , NULL , &sigset) < 0)
	{
		perror("sigprocmask error");
		return;
	}
	printf("%s" , str);
	
	if(sigismember(&sigset , SIGINT))
		printf("SIGINT ");
	if(sigismember(&sigset , SIGQUIT))
		printf("SIGQUIT ");
	if(sigismember(&sigset , SIGUSR1))
		printf("SIGUSR1 ");
	if(sigismember(&sigset , SIGALRM))
		printf("SIGALRM ");

	printf("\n");
	errno == errno_save;
}
int main(int argc ,char * argv[])
{
	pr_mask("Hello");
	return 0;
}
