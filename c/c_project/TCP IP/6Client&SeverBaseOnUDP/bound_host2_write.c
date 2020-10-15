#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// UDP比TCP快的地方无非就是UDP没有流控，没有握手，没有成功确认，一个数据包发过去就不管，从这个角度上说TCP是开销大一点
#define BUF_SIZE 30
void error_handling(char *message);
// ./eclient 127.0.0.1 9190
// 有数据边界的udp套接字 tcp不存在数据边界  但udp 一个写对应一个读  不能一个读对应多个写 
// 必须保证 udp的io 次数一致
// udp 数据报 -》 udp传输的数据包 与tcp不同 其本身为一个完整的数据 这与 udp存在数据的边界有关  所以 1个数据包为1个完整的数据

int main(int argc, char *argv[])
{
	int sock;
	char msg1[]="Hi!";
	char msg2[]="I'm another UDP host!";
	char msg3[]="Nice to meet you";

	struct sockaddr_in your_adr;
	socklen_t your_adr_sz;
	if(argc!=3){
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}
	
	sock=socket(PF_INET, SOCK_DGRAM, 0);   
	if(sock==-1)
		error_handling("socket() error");
	
	memset(&your_adr, 0, sizeof(your_adr));
	your_adr.sin_family=AF_INET;
	your_adr.sin_addr.s_addr=inet_addr(argv[1]);
	your_adr.sin_port=htons(atoi(argv[2]));
	
	//发送3次数据

	sendto(sock, msg1, sizeof(msg1), 0, 
					(struct sockaddr*)&your_adr, sizeof(your_adr));
	sendto(sock, msg2, sizeof(msg2), 0, 
					(struct sockaddr*)&your_adr, sizeof(your_adr));
	sendto(sock, msg3, sizeof(msg3), 0, 
					(struct sockaddr*)&your_adr, sizeof(your_adr));
	close(sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

/*
root@my_linux:/home/swyoon/tcpip# gcc bound_host2.c -o host2
root@my_linux:/home/swyoon/tcpip# ./host2
Usage : ./host2 <IP> <port>
root@my_linux:/home/swyoon/tcpip# ./host2 127.0.0.1 9190
root@my_linux:/home/swyoon/tcpip# 
*/
