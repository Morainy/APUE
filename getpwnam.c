/*************************************************************************
    > File Name: getpwnam.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年10月16日 星期四 21时29分35秒
 ************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <pwd.h>

static void my_alarm(int signo)
{
	struct passwd *rootptr;

	printf("in signal handler...\n");
	if( ( rootptr = getpwnam("root")) == NULL )
	{
		perror("getpwnam(root) error");
		return;
	}
	printf("rootptr->pw_name = %s\n" , rootptr->pw_name);
	printf("rootptr->pw_passwd = %s\n" , rootptr->pw_passwd);
	alarm(1);
	return;
}
int main(int argc ,char * argv[])
{
	struct passwd *ptr;

	signal(SIGALRM , my_alarm);
	alarm(1);
	for( ; ; )
	{
		//pause();
		if( (ptr = getpwnam("sys")) == NULL)
		{
			perror("getpwnam error");
			return -1;
		}
		if(strcmp(ptr->pw_name , "sys") != 0 )
		{
			printf("return value corrupted!, pw_name = %s\n" , ptr->pw_name);
		}
	/*	else
			printf("ptr->pw_name = %s\n" , ptr->pw_name);
	*/
	}

	return 0;
}

