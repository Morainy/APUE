/*************************************************************************
    > File Name: sleep.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年10月20日 星期一 16时10分49秒
 ************************************************************************/

#include <stdio.h>
#include <signal.h>

static void sig_alrm(int signo)
{
	printf("%d is caught\n" , signo);
	return 0;
}
unsigned int sleep(unsigned int nsecs)
{
	struct sigaction newact , oldact;
	sigset_t newmask , oldmask , suspmask;
	unsigned int unslept;

	/*set our handler ,save previous information*/
	newact.sa_handler = sig_alrm;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction(SIGALRM , &newact , &oldact);

	/* block SIGALRM and save current signal mask*/
	sigemptyset(&newmask);
	sigaddset(&newmask , SIGALRM);
	sigprocmask(SIG_BLOCK , &newmask , &oldmask);

	alarm(nsecs);
	suspmask = oldmask;
	sigdelset(&suspmask , SIGALRM);
	sigsuspend(&suspmask);

	/* some signal has been caught ,SIGALRM is now blocked*/
	unslept = alarm(0);
	sigaction(SIGALRM , &oldact , NULL);

	/*reset signal mask ,which unblock SIGALRM*/
	sigprocmask(SIG_SETMASK , &oldmask , NULL);
	return unslept;

}
int main(int argc, char const *argv[])
{
	while(1)
	{
		printf("^-^\t");
		fflush(stdout);
		sleep(3);
	}
	return 0;
}
