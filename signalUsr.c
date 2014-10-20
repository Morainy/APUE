/*************************************************************************
    > File Name: signalUsr.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年10月13日 星期一 10时49分10秒
 ************************************************************************/

#include <stdio.h>
#include <signal.h>

static void sig_usr(int);

int main(int argc ,char * argv[])
{
	if(signal(SIGUSR1 , sig_usr) == SIG_ERR)
	{
		perror("can't catch SIGUSR1'");
		return -1;
	}
	if(signal(SIGUSR2 , sig_usr) == SIG_ERR)
	{

		perror("can't catch SIGUSR2");
		return -1;
	}
	for( ; ; )
		pause();
	return 0;
}
static void sig_usr(int signo)
{
	switch(signo)
	{
		case SIGUSR1:
			printf("received SIGUSR1\n");
			break;
		case SIGUSR2:
			printf("received SIGUSR2\n");
			break;
		default:
			printf("received signal :  %d \n" , signo);
			break;
	}
}
