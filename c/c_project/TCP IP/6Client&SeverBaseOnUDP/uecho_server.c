#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30
void error_handling(char *message);
// UDP比TCP快的地方无非就是UDP没有流控，没有握手，没有成功确认，一个数据包发过去就不管，从这个角度上说TCP是开销大一点

// udp 与 tcp  仅仅在 主机内部 发挥作用  找路找到主机 是通过ip的作用  udp的速度比较快但是 他容易丢失
// 对于 压缩文件 不建议使用 丢一个 都解压不出来

// udp 是 无需面向连接的 过程 所以不需要tcp中的 listen 与 accept 函数 进行连接 
// udp 只有 创建套接字和数据交换的过程

//udp 的服务器与客户端 仅需 1个套接字 就像邮件到邮筒 的关系 只要附近 有一个邮筒 投进去就ok了 就可以送向世界各地
// tcp 是一对一 一个邮箱直达另一个邮箱 别的到不了


int main(int argc, char *argv[])
{
	int serv_sock;
	char message[BUF_SIZE];
	int str_len;
	socklen_t clnt_adr_sz;
	
	struct sockaddr_in serv_adr, clnt_adr;
	if(argc!=2){
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	
	serv_sock=socket(PF_INET, SOCK_DGRAM, 0);//创建udp邮箱
	if(serv_sock==-1)
		error_handling("UDP socket creation error");
	
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);// 应用本地
	serv_adr.sin_port=htons(atoi(argv[1]));// 规定端口
	
	if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)// 绑定
		error_handling("bind() error");

	
	char msg[]= "555\n"; // 自定义返回值

	while(1) 
	{
		clnt_adr_sz=sizeof(clnt_adr);
		str_len=recvfrom(serv_sock, message, BUF_SIZE, 0, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);// 利用bind函数分配的地址 来接受数据 什么种类的数据就ok了
		// 接受udp数据
		//serv_sock 用于接受udp套接字的描述符  message 保存数据的缓冲地址 BUF_SIZE 可接受的最大字节数 无法超过msg 的大小
		//0 可选参数 没有为0   (struct sockaddr*)&clnt_adr 存有发送端的地址信息的结构体变量地址 clnt_adr_sz 保存参数 (struct sockaddr*)&clnt_adr 的结构体变量长度的变量地址长度
		//message[10] = "888";
		printf("\n serve recv :  %s ",message);
		getchar();
		
		
		
		sendto(serv_sock, msg, strlen(msg), 0, (struct sockaddr*)&clnt_adr, clnt_adr_sz); // 没有 bind系统自己会分配端口
		//sendto(serv_sock, message, str_len, 0, (struct sockaddr*)&clnt_adr, clnt_adr_sz); // 没有 bind系统自己会分配端口
		//传输udp
		// 用于传输数据的udp套接字文件描述符 ，保存待传输数据的缓冲地址 ，待传数据长度，可选参数 无用0，to带有目标地址的结构体变量地址，传递参数to的结构体变量长度
		// 失败返回-1
	}	
	close(serv_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
