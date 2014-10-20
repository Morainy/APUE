#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>



void * mmapcopy(int fd , int size)
{
	char * buf;
	buf = mmap((void *)-1 , size , PROT_READ , MAP_PRIVATE , fd , 0);
	write( STDOUT_FILENO , buf ,size);
}
int main(int argc, char const *argv[])
{
	if(argc != 2)
	{
		printf("usage error\n");
		return -1;
	}
	struct stat fstat;
	int fd ;
	if((fd = open(argv[1] , O_RDONLY)) < 0)
	{
		printf("open error\n");
		return -1;
	}
	if(stat(argv[1] , &fstat) < 0)
	{
		printf("stat error\n");
		return -1;
	}
	mmapcopy(fd ,fstat.st_size);


	return 0;
}