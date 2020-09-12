#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

//  ./sever_tcp 9190

// 创建套接字 socket() -> 绑定套接字 bind() -> 等待连接请求 listen() -> 允许连接 accept() -> 数据交换 read()/write() -> 关闭连接 close()
// tcp/ip 协议栈--》 自底向上 数据链路层 （定义lan wlan标准 实现物理上的连接）- ip层（关注的是单个数据包 进行路径选择每次的路径的不同只是让到）
//					- 	tcp udp层 （通过ip提供的路径信息进行传递 关注的是一批数据包 关注数据包的顺序 及 完整性 ）


void error_handling(char *message);

int main(int argc, char *argv[])
{
	int serv_sock;
	int clnt_sock;

	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;

	char message[]="Hello World!";
	
	if(argc!=2){
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	
	serv_sock=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);//ipv4（协议族） ，面向连接的套接字（传输方式）or 面向消息的 本次是面向连接的 ， 0 《-（同一协议族有不同的不同的传输方式的化 写IPPROTO_TCP OR IPPROTO_UDP 反之为0就ok）
	// 前两个定下来了第三个可以为0 已经定死了
	//int tcp_socket = socket(PF_INET, SOCK_STREAM,IPPROTO_TCP )
	if(serv_sock == -1)
		error_handling("socket() error");
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY); // INADDR_ANY 指定 本机的ip地址
	serv_addr.sin_port=htons(atoi(argv[1]));
	
	if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1)	//	向套接字 电话机 分配，绑定 ip地址
		error_handling("bind() error"); 
	
	if(listen(serv_sock, 5)==-1)// 等待请求  因为一次只能处理一个请求 多来的进入接待室 第二个参数 限定接待室的大小 为队列 忙的web服务器 接待室为15 
		error_handling("listen() error");
	
	clnt_addr_size=sizeof(clnt_addr);  
	clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_addr,&clnt_addr_size);//接受处理 处理请求 及 接待室的请求  与请求的客户端 进行连接 
	if(clnt_sock==-1)
		error_handling("accept() error");  
	
	write(clnt_sock, message, sizeof(message));//	向客户端 传递数据
	close(clnt_sock);	//	关闭 客户端 连接
	close(serv_sock);	//	关闭 服务器 关闭
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
