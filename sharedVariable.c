/*************************************************************************
    > File Name: sharedVariable.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年10月10日 星期五 21时29分41秒
 ************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

void * thread(void *);
int cnt;
const int count = 1000000;
sem_t mutex;

int main(int argc , char * argv[])
{

	pthread_t tid1 , tid2;
	sem_init(&mutex , 0 , 1);
	pthread_create(&tid1 , NULL , thread , NULL);
	pthread_create(&tid2 , NULL , thread , NULL);

	pthread_join(tid1 , NULL);
	pthread_join(tid2 , NULL);
	printf("cnt = %d\n" , cnt);
	pthread_exit(0);

}

void * thread(void * arg)
{
	int i;
	sem_wait(&mutex);
	for( i = 0 ; i < count ;i++)
		cnt++;
	sem_post(&mutex);
}
