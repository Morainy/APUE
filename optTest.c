#include <stdio.h>
#include <getopt.h>
#include <netdb.h>
#include <sys/socket.h>

#define no_argument 0
#define required_argument 1
#define optional_argument 2	

const struct option opts[]=
	{
		{"help" , 0 , NULL , 'h'},
		{"server" , 1 , NULL , 's'},
		{"background" , 0 , NULL , 'b'},
		{NULL , 0 , NULL , 0}
	};
char * const short_opt = "ts: bhd:";
int main(int argc, char * const argv[])
{
	int rc;
	char * soption;
	char * target;
	struct hostent *host = NULL;
	char ** pptr;
	char str[32];
	while((rc = getopt_long(argc , argv , short_opt , opts , NULL)) != -1)
	{
		//printf("argc = %d\n",argc);
		switch(rc)
		{
			case 'h':
				printf("argument is -h\n");
				printf("optarg = %s\n",optarg );
				printf("optind = %d\n",optind );
				printf("argv[optind] = %s\n",argv[optind]);
				break;
			case 's':
				soption = optarg;
				printf("optarg = %s\n",optarg );
				printf("optind = %d\n",optind );
				printf("argv[optind] = %s\n",argv[optind]);
				printf("argument is -s\n");
				printf("soption = %s\n",soption );
				break;
			case 'b':
				printf("argument is -b\n");
				break;
			case 't':
				printf("argument is -t\n");
				break;
			case 'd':
				if(optarg == 0)
					host = gethostbyname(argv[optind]);
				else
					host = gethostbyname(optarg);
				break;
		}
		if(host)
		{
			printf("official name =  %s\n",host->h_name);
			for(pptr = host->h_aliases ; *pptr ; pptr++)
				printf("aliases = %s\n",*pptr);
			for(pptr = host->h_addr_list ; *pptr ; pptr++)
			{
				inet_ntop(host->h_addrtype, *pptr, str, sizeof(str));
				printf(" address:%s\n",str);
			}
			inet_ntop(host->h_addrtype, host->h_addr, str, sizeof(str));
			printf("first address: %s\n",str);
		}
	}
	return 0;
}