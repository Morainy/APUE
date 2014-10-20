/*************************************************************************
    > File Name: newFile.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年09月20日 星期六 10时46分00秒
 ************************************************************************/

#include <stdio.h>
#include <fcntl.h>

#define  FILE_MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)
#define file_size (100*1024*1024)
int main(int argc, char const *argv[])
{
	int fd = creat("file.test" , FILE_MODE);
	int i;
	char ch = 'a';
	for(i = 0 ; i <file_size ; i++)
	{
		write(fd , &ch , sizeof(ch));
	}
	close(fd);
	return 0;
}
