#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// UDP比TCP快的地方无非就是UDP没有流控，没有握手，没有成功确认，一个数据包发过去就不管，从这个角度上说TCP是开销大一点

#define BUF_SIZE 30
void error_handling(char *message);

int main(int argc, char *argv[])
{
	int sock;
	char message[BUF_SIZE];
	int str_len;
	socklen_t adr_sz;
	
	struct sockaddr_in serv_adr, from_adr;
	if(argc!=3){
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}
	
	sock=socket(PF_INET, SOCK_DGRAM, 0);  // 创建udp 📞电话机/邮筒 
	if(sock==-1)
		error_handling("socket() error");
	
	memset(&serv_adr, 0, sizeof(serv_adr));

	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_adr.sin_port=htons(atoi(argv[2]));
	//设定 目标地址

	while(1)
	{
		fputs("Insert message(q to quit): ", stdout);
		fgets(message, sizeof(message), stdin);     
		if(!strcmp(message,"q\n") || !strcmp(message,"Q\n"))	
			break;
		
		sendto(sock, message, strlen(message), 0, (struct sockaddr*)&serv_adr, sizeof(serv_adr)); // 发送数据
		//传输udp
		// 用于传输数据的udp套接字文件描述符 ，保存待传输数据的缓冲地址 ，待传数据长度，可选参数 无用0，to带有目标地址的结构体变量地址，传递参数to的结构体变量长度
		// 失败返回-1
		adr_sz=sizeof(from_adr);
		str_len=recvfrom(sock, message, BUF_SIZE, 0, (struct sockaddr*)&from_adr, &adr_sz); //接受数据
		// 接受udp数据
		//serv_sock 用于接受udp套接字的描述符  message 保存数据的缓冲地址 BUF_SIZE 可接受的最大字节数 无法超过msg 的大小
		//0 可选参数 没有为0   (struct sockaddr*)&clnt_adr 存有发送端的地址信息的结构体变量地址 clnt_adr_sz 保存参数 (struct sockaddr*)&clnt_adr 的结构体变量长度的变量地址长度
		
		message[str_len]=0;
		printf("Message from server: %s", message);
	}	
	close(sock); // 断开连接
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}