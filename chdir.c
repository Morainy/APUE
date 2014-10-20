/*************************************************************************
    > File Name: chdir.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年09月23日 星期二 21时23分15秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(int argc , char * argv[])
{
	if(chdir("/tmp") < 0)
	{
		perror("chdir failed\n");
		return -1;
	}
	printf("chdir to /tmp succeeded\n");
	return 0;
}
