#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

//linux -c

//gcc -g Hello_Sever.c -o main_2
//./main_2

int main(int argc, char *argv[]){
    int serv_sock; //service  安装电话机
    int clnt_sock; //clink 

    char msg[] = "Hello world !!\n";

    if(argc != 2){
        printf("Usage : %s <- port using \n",argv[0]);
        exit(1);
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sock == -1) error_handing("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  
    serv_addr.sin_port = htons(atoi(argv[1]));

    if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1) error_handing("bind() error");
    if(listen(serv_sock, 5) == -1) error_handing("listen() error");

    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, msg, sizeof(msg));

}