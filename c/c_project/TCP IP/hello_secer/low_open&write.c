#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 100

void error_handling(char* message);

int main(void)
{
	int fd;//内核（kernel）利用文件描述符（file descriptor）来访问文件
	char buf[]="Let's go!\n";
	char bufRead[BUF_SIZE];
	
	fd=open("./data.txt", O_CREAT|O_WRONLY|O_TRUNC);	//创建文件
	if(fd==-1) error_handling("open() error!");
	printf("file descriptor: %d \n", fd);

	if(write(fd, buf, sizeof(buf))==-1) error_handling("write() error!"); //写入文件 并测试
	close(fd);

	fd=open("./data.txt", O_RDONLY);// 读取文件
	if(read(fd, bufRead, sizeof(bufRead))==-1) error_handling("read() error!");//打开文件 并读
	printf("file data: %s file descriptor  %d ", bufRead,fd);
	
	close(fd);


	return 0;
}

void error_handling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

/*
文件描述符：在linux系统中打开文件就会获得文件描述符，它是个很小的非负整数。每个进程在PCB（Process Control Block）中保存着一份文件描述符表，文件描述符就是这个表的索引，每个表项都有一个指向已打开文件的指针。

文件指针：C语言中使用文件指针做为I/O的句柄。文件指针指向进程用户区中的一个被称为FILE结构的数据结构。
		FILE结构包括一个缓冲区和一个文件描述符。
		而文件描述符是文件描述符表的一个索引，
		因此从某种意义上说文件指针就是句柄的句柄（在Windows系统上，文件描述符被称作文件句柄 handal）
*/
