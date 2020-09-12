#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

//  ./client_tcp 127.0.0.1 9190

// socket()创建套接字  -> connect()请求连接 【请求 服务器 的 listen()  】 -> read()/write()交换数据 -> close()断开连接

void error_handling(char *message);

int main(int argc, char* argv[])
{
	int sock;
	struct sockaddr_in serv_addr;
	char message[30];
	int str_len=0;
	int idx=0, read_len=0;
	
	if(argc!=3){
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}
	
	sock=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // 有SOCK_STREAM默认为IPPROTO_TCP 所以为0 用udp不行
	//sock=socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP); 
	if(sock == -1)
		error_handling("socket() error");
	
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;	// sin_family 地址组 ipv4
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]); //  sin_addr 32位ip地址 s_addr--》32位 的ipv4 地址----> inet_addr 将十进制转为 32位
	serv_addr.sin_port=htons(atoi(argv[2])); // sin_port 16位端口号
			//由于不同的cpu的字符排序（大端序与小端序）不同 所以 字符在传递的时候应当格式化 htons--》 h 主机 n 网络标准 s short字符  
			//将htons --》 h to n s h的s变为n
			//
	
	for(int i =0; i<3000; i++) printf("wait time %d",i);//等待时间 让服务器可能有多个write发完  让read一次性读完
	
	if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1) // 第二个参数 期望得到 sockaddr 结构变量的地址
		error_handling("connect() error!");// 在connect中进行分配 ip 和 端口号  -》在内核中进行 无需bind 分配

	while(read_len=read(sock, &message[idx++], 1))
	{
		if(read_len==-1)
			error_handling("read() error!");
		str_len+=read_len;
	}


	printf("Message from server: %s \n", message);
	printf("Function read call count: %d \n", str_len);
	close(sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
