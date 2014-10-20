/*************************************************************************
    > File Name: getuidTest.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年09月26日 星期五 10时31分45秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(int argc , char * argv[])
{
	printf("getuid() = %d getguid() = %d geteuid() = %d\n" , getuid() , getguid() , geteuid());
}
