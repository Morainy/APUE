/*************************************************************************
    > File Name: Myls.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年10月11日 星期六 11时12分28秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(int argc ,char * argv[])
{
	char * argvl[] = {"ls" , "-l"};
	char * env[] = {0 , NULL};
	int rtn;
	if( (rtn = execve("/bin/ls" , argv , env)) < 0)
	{
		perror("execve error");
		return -1;
	}
	return 0;
}
