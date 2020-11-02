#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
void error_handling(char *message);

// 通过 名字 得到 主机

int main(int argc, char *argv[])
{
	int i;
	struct hostent *host;
	if(argc!=2) {
		printf("Usage : %s <addr>\n", argv[0]);
		exit(1);
	}
	
	host=gethostbyname(argv[1]);// 利用域名获取地址
	if(!host)
		error_handling("gethost... error");
// 以下为hostent 结构体的 成员变量的 内容 
	printf("Official name: %s \n", host->h_name);// 官方域名
	
	for(i=0; host->h_aliases[i]; i++)
		printf("Aliases %d: %s \n", i+1, host->h_aliases[i]);// 通过多个域名访问 同一主页 除官方域名外 还可以指定其他的 保存在Aliases （额外的）
	
	printf("Address type: %s \n", 
		(host->h_addrtype==AF_INET)?"AF_INET":"AF_INET6");// ip地址 的类型 host->h_addrtype
			//  host->h_length ：保存ip的地址长度 ipv4 4个字节 ipv4 16个字节
	for(i=0; host->h_addr_list[i]; i++)
		printf("IP addr %d: %s \n", i+1,
					inet_ntoa(*(struct in_addr*)host->h_addr_list[i]));// 存放ip地址的地址族信息 支持ipv4 与ipv6
					// 通过此变量 以整数的形式 保存域名对应的 ip地址
					// 用户过多的网站 可以给多个ip 分配同一个域名 来进行负载均衡
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
