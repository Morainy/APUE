#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAXLINE 1024

int main(int argc, char const *argv[])
{

	struct stat buf;
	char ch[MAXLINE];
	stat("/etc/hosts" , &buf);
	snprintf(ch , sizeof(ch) ,"%s" ,ctime( &buf.st_mtime));
	printf("strlen(ch) = %d\n",strlen(ch));
	printf("buf.st_mtime =  %s\n",ch );
	
	printf("/etc/hosts file size : %ld\n",buf.st_size);
	return 0;
}