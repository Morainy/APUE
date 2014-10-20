#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char const *argv[])
{
	struct passwd * pwd;
	pwd = getpwuid(getuid());
	printf("username = %s\n",pwd->pw_name );
	printf("user password = %s\n",pwd->pw_passwd );
	printf("user ID = %d\n",pwd->pw_uid );
	printf("group ID = %d\n",pwd->pw_gid );
	printf("user information = %s\n",pwd->pw_gecos );
	printf("home directory = %s\n",pwd->pw_dir );
	printf("shell program = %s\n",pwd->pw_shell );
	return 0;
}