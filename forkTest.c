/*************************************************************************
    > File Name: forkTest.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年09月29日 星期一 22时06分58秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void doit()
{
	fork();
	fork();
	printf("hello\n");
	exit(0);
}
int main(int argc ,char * argv[])
{
	/*int i;

	for(i = 0 ; i < 2 ; i++)
		fork();
	printf("Hello\n");
	exit(0);*/
	doit();
	printf("Hello\n");
	exit(0);
}
