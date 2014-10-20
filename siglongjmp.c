#include <setjmp.h>
#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

static void sig_usr1(int) , sig_alarm(int);
static sigjmp_buf jmpbuf;
static volatile sig_atomic_t canjump;
void err_sys(const char *);
void pr_mask(const char *);

void err_sys(const char * str)
{
	perror(str);
	exit(-1);
}
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
int main(int argc, char const *argv[])
{
	if(signal(SIGUSR1 , sig_usr1) == SIG_ERR)
		err_sys("signal(SIGUSR1) error ");
	if(signal(SIGALRM , sig_alarm)== SIG_ERR)
		err_sys("signal(SIGALRM) error");
	pr_mask("starting main:");
	if(sigsetjmp(jmpbuf , 1))
	{
		pr_mask("ending main");
		exit(0);
	}
	canjump = 1;
	for( ; ; )
		pause();
}
static void sig_usr1(int signo)
{
	time_t starttime;
	if(canjump == 0)
		return;
	pr_mask("starting sig_usr1:");
	alarm(3);
	starttime = time(NULL);
	for( ; ; )
		if(time(NULL) > starttime + 5)
			break;
	pr_mask("finishing sig_usr1:");
	canjump = 0;
	siglongjmp(jmpbuf , 1 );
}
static void sig_alarm(int signo)
{
	pr_mask("in sig_alarm:");
}