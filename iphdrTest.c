/*************************************************************************
    > File Name: iphdrTest.c
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年09月27日 星期六 09时40分56秒
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <linux/ip.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>

char buf[65535];

int main(int argc, char const *argv[])
{
	int length = sizeof(struct iphdr);
	struct iphdr *ip = (struct iphdr *)malloc(length);
	struct timeval timestamp;
	gettimeofday(&timestamp , NULL);
	printf("timestamp = %s",ctime((time_t*)&timestamp));
	printf("ip->ihl = %d \n", ip->ihl);
	printf("ip->version = %d\n",ip->version);
	printf("ip->tos = %d \n",ip->tos);
	int sockfd = socket(AF_INET , SOCK_RAW , IPPROTO_TCP|IPPROTO_UDP|IPPROTO_ICMP);
	int n , i;
	struct sockaddr src_addr;
	socklen_t addrlen = sizeof(struct sockaddr);
	bzero(&src_addr , sizeof(struct sockaddr));
	while(1)
	{
		n = recvfrom(sockfd , buf , sizeof(buf) , 0 , &src_addr , &addrlen);
		for(i = 0 ; i < n ; i++)
		{
			printf("0x%x ",buf[i]);
		}
	}
	for(i = 0 ; i < length ;i++)
	{
		printf("0x%x ",((char*)ip)[i]);
	}

	free(ip);
	return 0;
}
