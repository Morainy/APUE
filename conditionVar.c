/*************************************************************************
    > File Name: conditionVar.c
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2014年10月23日 星期四 11时04分48秒
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void * thread1(void *);
void * thread2(void *);
volatile int i;
int main(int argc ,char *argv[])
{
	pthread_t tid1 , tid2;
	pthread_create(&tid1 , NULL , thread1 , NULL);
	pthread_create(&tid2 , NULL , thread2 , NULL);

	pthread_join(tid1 , NULL);
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	exit(0);
}
void * thread1(void * arg)
{

	for(i = 1 ; i < 9 ; i++)
	{
		pthread_mutex_lock(&mutex);
		printf("thread1 start:\n");
		if(i % 3 == 0)
		{
			pthread_cond_signal(&cond);
		}
		printf("thread1 : %d\n" , i);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}
void * thread2(void * arg)
{
	while(i < 9)
	{
		pthread_mutex_lock(&mutex);
		printf("thread2 start:\n");
		if(i % 3 != 0)
		{
			pthread_cond_wait(&cond , &mutex);
		}
		printf("thread2 : %d\n", i);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}
