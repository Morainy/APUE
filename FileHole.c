#include <stdio.h>
#include <fcntl.h>
#define  FILE_MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)

char buf1[] = "abcdefghi";
char buf2[] = "ABCDEFGHI";

int main(int argc, char const *argv[])
{
	int fd ;
	if( (fd = creat("file.hole" , FILE_MODE) )< 0 )
	//if( (fd = open("file.hole" , O_WRONLY)) < 0 );
	{
		perror("creat error\n");
		return -1;
	}
	printf("fd = %d\n",fd );

	if( write(fd , buf1 , 10) != 10)
	{
		perror("write  buf1 error\n");
		return -1;
	}
	if( lseek(fd , 16384 , SEEK_SET) == -1 )
	{
		perror("lseek error\n");
		//return -1;
	}
	if(write(fd , buf2 , 10) != 10 )
	{
		perror("write buf2 error\n");
		return -1;
	}
	printf("Done!\n");
	return 0;
}