#include <netinet/in.h> //Internet Addressing library.
#include <stdio.h> //Standard input output header.
#include <stdlib.h> //Standard library for general purpouse
#include <sys/socket.h> //Socket API library.
#include <sys/types.h>  //Extended data types library.
#include <arpa/inet.h> // IPv4 address manipulation
#include <string.h>

int main(){
    
    char msgptr[255] = "Hello World!.\n"; 

    int sockfd = socket(AF_INET, SOCK_STREAM, 0); //TCP IPv4 socket.

    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(9999);
    sockaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //We only want to connet over the loopback.

    int sockbind = bind(sockfd, (struct sockaddr*)&sockaddr, sizeof(sockaddr)); 

    if (sockbind == 0){
        printf("[+] Socket binded successfully on address 127.0.0.1:9999.\n");
    }

    int socklisten = listen(sockfd, 1);

    if (socklisten == 0){
        printf("[+] Socket is listening...\n");
    }

    int clientaccept = accept(sockfd, NULL, NULL);

    if (clientaccept != -1) {
        printf("[+] Received client connection!\n");
    }

    int msgsend=send(clientaccept, msgptr, strlen(msgptr), 0);

    if (msgsend != -1){

        printf("[+] %d bytes sended to client.\n", msgsend);

    }

    

    return 0;
}