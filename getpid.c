/*************************************************************************
    > File Name: getpid.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年09月16日 星期二 20时33分49秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	printf("hello World From process id : %d\n",getpid());
	return 0;
}
