#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

//前面 close 或者 closeSocket 的是单方面断开的 close 或者 closeSocket --》 双向全部断开 一方面全部断开 另一台机器被迫关闭
// 所以 提出了 half-close 半关闭 -》 只能接受数据不再发送数据 或者 只能发送数据不能接受数据

//两台主机通过套接字建立连接后进入可交换数据的状态，又称“流形成的状态”。
//也就是把建立套接字后可交换数据的状态看作是一种流，此处的流可以比作水流，
//水朝着一个方向流动，同样，在套接字的流中，数据也只能向一个方向移动，因此，为了进行双向通信，需要2个流。

//2.UDP中能否形成流？请说明原因。
//答：UDP不能形成流， SOCK_DGRAM 表明数据将是数据报(datagrams)的形式

#define BUF_SIZE 30
void error_handling(char *message);

int main(int argc, char *argv[])
{
	int sd;
	FILE *fp;
	
	char buf[BUF_SIZE];
	int read_cnt;
	struct sockaddr_in serv_adr;
	if(argc!=3) {
		printf("Usage: %s <IP> <port>\n", argv[0]);
		exit(1);
	}
	
	fp=fopen("receive.dat", "wb");//  创建新文件 来保存 服务器传输端的 文件数据
	sd=socket(PF_INET, SOCK_STREAM, 0);   

	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_adr.sin_port=htons(atoi(argv[2]));

	connect(sd, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
	
	printf("\n");
	while((read_cnt=read(sd, buf, BUF_SIZE ))!=0){
		fwrite((void*)buf, 1, read_cnt, fp);// 将接受的文件 一个 一个的写入 新建的文件中 直达接收到eof为止
		printf(" * ");
	}
	printf("\n");	

	puts("Received file data");
	write(sd, "Thank you", 10);
	fclose(fp);
	close(sd);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}