#include <stdio.h>
#include <unistd.h>

#define pathSize 1024

int main(int argc, char const *argv[])
{
	char  ptr[pathSize];

	if(chdir("/home/morain") < 0)
	{
		perror("chdir error\n");
		return -1;
	}

	if(getcwd(ptr , pathSize) < 0)
	{
		perror("getcwd error \n");
		return -1;
	}
	printf("cwd = %s\n",ptr);
	return 0;
}