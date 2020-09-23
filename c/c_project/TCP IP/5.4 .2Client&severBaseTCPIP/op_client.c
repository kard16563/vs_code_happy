#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define RLT_SIZE 4 //运算数字 的字节 大小
#define OPSZ 4 // 结果数字 的字节 大小


void error_handling(char *message);

int main(int argc, char *argv[])
{
	int sock;
	char opmsg[BUF_SIZE];
	int result, opnd_cnt, i;
	struct sockaddr_in serv_adr;
	if(argc!=3) {
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}
	
	sock=socket(PF_INET, SOCK_STREAM, 0);   
	if(sock==-1)
		error_handling("socket() error");
	
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_adr.sin_port=htons(atoi(argv[2]));
	
	if(connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
		error_handling("connect() error!");
	else
		puts("Connected...........");
	
	fputs("Operand count: ", stdout);
	scanf("%d", &opnd_cnt);

	

	opmsg[0]=(char)opnd_cnt;//将 长度（转为char）放入 数组中的第1给位置
	
	for(i=0; i<opnd_cnt; i++)
	{
		printf("Operand %d: ", i+1);
		scanf("%d", (int*)&opmsg[i*OPSZ+1]);
		printf("add-> %p ",&opmsg[i*OPSZ+1]);
	}

	fgetc(stdin);// 删除缓冲字符 换行符\n
	fputs("Operator: ", stdout);
	scanf("%c", &opmsg[opnd_cnt*OPSZ+1]);
	write(sock, opmsg, opnd_cnt*OPSZ+2); //write (int fd, const void * buf, size_t count);  从fd中 向buf所指的区域写入 count个字符 
	read(sock, &result, RLT_SIZE);// 数据先进入缓冲区 缓冲量的大小 可以通过滑窗进行调节 再读 
	
	printf("Operation result: %d \n", result);
	close(sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}