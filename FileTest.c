/*************************************************************************
    > File Name: FileTest.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年09月19日 星期五 19时21分10秒
 ************************************************************************/

#include <stdio.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	//close(0);
	//close(1);
	//close(2);
	int num = 0;
	int ret;

	if(scanf("%d" , &num) < 0)
	{
		printf("scanf error from printf\n");
		perror("scanf error from perror\n");
	}
	if( ret = printf("num = %d\n",num ) > 0)
	{
		printf("ret = %d\n",ret );
		perror("printf error\n");
	}

	return 0;
}
