#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
// UDP比TCP快的地方无非就是UDP没有流控，没有握手，没有成功确认，一个数据包发过去就不管，从这个角度上说TCP是开销大一点
// 创建 连接的 udp
// 在 bound host2 write 中需要向一个地址持续写 3条地址 因为他没有注册 所以每一次写入要进行（sendto前）重复注册  然后再删除 套接字中注册的地址信息

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
	
	sock=socket(PF_INET, SOCK_DGRAM, 0);   
	if(sock==-1)
		error_handling("socket() error");
	
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_adr.sin_port=htons(atoi(argv[2]));
	
	connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr));// 注册待传信息的ip地址 与端口号  没有这个的化会自动默认进行注册 
		//但是不利于重复传输 因为系统会重复注册

	// 在传输对象固定的情况下和与对象传输大量的数据的情况下 定死进行连接  与bound对比 

	while(1)
	{
		fputs("Insert message(q to quit): ", stdout);
		fgets(message, sizeof(message), stdin);     
		if(!strcmp(message,"q\n") || !strcmp(message,"Q\n"))	
			break;
		/*
		sendto(sock, message, strlen(message), 0, 
					(struct sockaddr*)&serv_adr, sizeof(serv_adr));
		*/
		write(sock, message, strlen(message)); // 代替 sendto

		/*
		adr_sz=sizeof(from_adr);
		str_len=recvfrom(sock, message, BUF_SIZE, 0, 
					(struct sockaddr*)&from_adr, &adr_sz);
		*/
		str_len=read(sock, message, sizeof(message)-1);// 代替 recvfrom

		message[str_len]=0;
		printf("Message from server: %s", message);
	}	
	close(sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
