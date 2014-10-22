/*************************************************************************
    > File Name: printids.c
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2014年10月21日 星期二 09时33分15秒
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

pthread_t ntid;

void printids(const char * str)
{
	pid_t pid;
	pthread_t tid;
	pid = getpid();
	tid = pthread_self();
	printf("%s pid %u tid %u (0x%x)\n" , str , (unsigned)pid , (unsigned)tid 
			, (unsigned)tid);
}
void * thr_fn(void * arg)
{
	printids("new threads:");
	return ((void *)0);
}
int main(int argc ,char * argv[])
{
	int err;
	err = pthread_create(&ntid , NULL , thr_fn , NULL);
	if(err != 0)
	{
		//err_quit("can't create thread : %s \n" , strerror(err));
		printf("can't create thread : %s \n" , strerror(err) );
		return -1;
	}
	printids("main thread");
	sleep(1);
	exit(0);
}
