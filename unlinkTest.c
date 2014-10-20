#include <stdio.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	if(creat("tempfile" , S_IRWXU | S_IRWXG | S_IRWXO) < 0)
	{
		perror("create error\n");
		return -1;
	}
	if(open("tempfile" , O_RDWR) < 0 )
	{	
		perror("open error\n");
		return -1;
	}
	if(unlink("tempfile") < 0)
	{
		perror("unlink error\n");
		return -1;
	}
	printf("file unlink\n");
	sleep(15);
	printf("done!\n");
	return 0;
}