#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>

#ifdef OPEN_MAX
static long openmax = OPEN_MAX;
#else
static long openmax = 0;
#endif

#define OPEN_MAX_GUESS 256

long open_max(void)
{
	if(openmax == 0)
	{
		errno = 0;
		if( ( openmax = sysconf(_SC_OPEN_MAX)) < 0 )
		{
			if(errno == 0)
			{
				openmax = OPEN_MAX_GUESS;
				
			}
			else
			{
				printf("sysconf error for _SC_OPEN_MAX\n");
				return -1;
			}
		}
	}
	return openmax;
}
int main(int argc, char const *argv[])
{
	printf("open_max() =  %ld\n",open_max());
	return 0;
}