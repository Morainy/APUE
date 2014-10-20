/*************************************************************************
    > File Name: sigprocmask.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年10月18日 星期六 10时07分00秒
 ************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

static void sig_quit(int);

void err_sys(const char * str)
{
	perror(str);
	exit(-1);
}
int main(int argc, char const *argv[])
{
	sigset_t newmask, oldmask , pendmask;
	if(signal(SIGQUIT , sig_quit) == SIG_ERR)
		err_sys("can't catch SIGQUIT");

	sigemptyset(&newmask);
	sigaddset(&newmask , SIGQUIT);
	if(sigprocmask(SIG_BLOCK , &newmask , &oldmask) < 0)
		err_sys("SIG_BLOCK error");
	sleep(5);
	if(sigpending(&pendmask) < 0)
		err_sys("sigpending error");
	if(sigismember(&pendmask , SIGQUIT))
		printf("\nSIGQUIT pending\n");

	if(sigprocmask(SIG_SETMASK , &oldmask , NULL) < 0)
		err_sys("SIG_SETMASK error");
	printf("SIGQUIT unblocked\n");
	sleep(5);
	exit(0);
}

static  void sig_quit(int signo)
{
	printf("caught SIGQUIT\n");
	if(signal(SIGQUIT , SIG_DFL) == SIG_ERR)
		err_sys("can't reset SIGQUIT");
}
