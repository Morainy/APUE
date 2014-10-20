#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	struct utsname  *bufName = (struct utsname *)malloc(sizeof(struct utsname));
	int rtn = uname(bufName);
	printf("sysname = %s\n",bufName->sysname);
	printf("nodename = %s\n",bufName->nodename);
	printf("release = %s\n",bufName->release);
	printf("version = %s\n",bufName->version);
	printf("machine = %s\n",bufName->machine);
	free(bufName);
	return 0;
}