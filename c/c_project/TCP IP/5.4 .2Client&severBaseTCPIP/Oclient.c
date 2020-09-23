#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>


// ./eclient 127.0.0.1 9190
#define BUF_SIZE 1024


#define RLT_SIZE 4
#define OPSZ 4

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int sock;
	char message[BUF_SIZE];
	int str_len, recv_len, recv_cnt;
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

    int num = 0;
    char opmsg[BUF_SIZE];
	int i=0;
	int result;

	// while(1) 
	// {
		fputs("Input message(Q to quit): ", stdout);
		scanf("%d", &num);

        opmsg[0] = (char)num; //将 数字放入字符串中
        
        for( i =0 ; i<num; i++){
			int tt =i;
            printf("op num %d :",tt+1);
            scanf("%d", (int*)&opmsg[i*OPSZ+1]);// 将读取的数字放入 字符串 数组中   原本为字符串数组
        }
		fgetc(stdin);
        printf("Operator: ");
        scanf("%c", &opmsg[i*OPSZ+1]);
        write(sock, opmsg, num*OPSZ+2);//第三个参数 放入数据的大小
		read(sock, &result, RLT_SIZE);
		printf("result ->  %d ",result);
        
	
	close(sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
