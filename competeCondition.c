#include <stdio.h>
#include <unistd.h>

static void charactertime(char * );
int main(int argc, char const *argv[])
{
	pid_t pid;
	if( (pid = fork()) < 0 )
	{
		printf("fork error\n");
		return -1;
	}
	else if(pid == 0)
	{
		charactertime("output from child\n");
	}
	else
	{
		charactertime("output from parent\n");
	}
	return 0;
}
static void charactertime(char * str)
{
	char * ptr;
	int c;
	setbuf(stdout, NULL);
	for(ptr = str ; (c = *ptr++) != 0 ; )
	{
		putc(c , stdout);
	}
}