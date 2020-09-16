#include <stdio.h>
#include <arpa/inet.h>

// inet ----> 初始化操作
int main(int argc, char *argv[])
{

	char *addr1="127.212.124.78";
	char *addr2="127.212.124.325";

	unsigned long conv_addr=inet_addr(addr1);	//	初始化 将十进制转为 16 进制
	
	if(conv_addr==INADDR_NONE)
		printf("Error occured! \n");
	else
		printf("Network ordered integer addr: %#lx \n", conv_addr);

	conv_addr=inet_addr(addr2); // inet_addr  处理addr2 时发现 addr 不符合 ip地址的要求所以 无法转换处理
	if(conv_addr==INADDR_NONE)
		printf("Error occureded \n");
	else
		printf("Network ordered integer addr: %#lx \n\n", conv_addr);

	char *addr="127.232.124.79";// inet_aton 与 inet_addr 函数在功能上完全相同  将ip 转换位 32位 网络字节序整数 并返回 只不过用了in_addr 结构体
	struct sockaddr_in addr_inet;
	
	if(!inet_aton(addr, &addr_inet.sin_addr))
		error_handling("Conversion error");
	else
		printf("Network ordered integer addr: %#x \n", addr_inet.sin_addr.s_addr);
	
	return 0;

}