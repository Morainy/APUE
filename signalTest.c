/*************************************************************************
    > File Name: signalTest.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年09月30日 星期二 08时39分19秒
 ************************************************************************/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

char * globalPtr;
void handler(int sig)
{
	printf("handler printf\n");
	exit(0);
}
int main(int argc ,char * argv[])
{
	int i;
	globalPtr = (char *)malloc(sizeof(char) * 256);
	for(i = 0 ; i <= 512 ; i++)
	{
		if(i %20 == 0)
		{
			printf("\n");
		}
		printf("%x ",globalPtr[i]);
	}
	printf("\n");
	signal(SIGINT , handler);
	printf("main Hello \n");
	pause();
}
