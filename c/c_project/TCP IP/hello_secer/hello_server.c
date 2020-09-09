#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

//服务器端的 套接字 ---》 监听套接字

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int serv_sock; //service  安装电话机
	int clnt_sock; // clink 

	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;

	char message[] = "Hello World!";
	
	printf(" %d \n",argc);// 输入的字符段 $ ./hserver 9190 2个

	if(argc != 2){
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	printf("\n 准备接受请求..... 1\n");
	
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	printf("\n 准备接受请求..... 2\n");
	if(serv_sock == -1) error_handling("socket() error");
	
	memset(&serv_addr, 0, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));
		printf("\n 准备接受请求..... 3\n");
	if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1 ) error_handling("bind() error"); //拨号
		printf("\n 准备接受请求..... 4\n");
	if(listen(serv_sock, 5) == -1) error_handling("listen() error");//连接电话线
	
	clnt_addr_size = sizeof(clnt_addr);

	printf("\n 准备接受请求..... 5\n");
	clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr,&clnt_addr_size);//拿起电话桶 接听信息
	printf("\n 接受到请求....正在处理中... \n");
	if(clnt_sock == -1) error_handling("accept() error");  
	write(clnt_sock, message, sizeof(message));// 写入消息 发送给客户端
	close(clnt_sock);	//关闭
	close(serv_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
