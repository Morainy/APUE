#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c ;
	while((c = getc(stdin)) != EOF )
	{
		//printf("c = %d",c );
		if(putc(c , stdout) == EOF)
		{
			perror("output error\n");
			return -1;
		}
		//printf("\n");
	}
	if(ferror(stdin))
	{
		perror("input error\n");
		return -1;
	}
	return 0;
}