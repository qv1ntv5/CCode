#include <netinet/in.h> //Internet Addressing library.
#include <stdio.h> //Standard input output header.
#include <stdlib.h> //Standard library for general purpouse
#include <sys/socket.h> //Socket API library.
#include <sys/types.h>  //Extended data types library.
#include <arpa/inet.h> // IPv4 address manipulation
#include <string.h>

int main(){

    int sockfd = socket(AF_INET, SOCK_STREAM, 0); //TCP IPv4 socket.

    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(9999);
    sockaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //We define the ip and the port we want to connect.

    int sockconnect = connect(sockfd, (struct sockaddr*)&sockaddr, sizeof(sockaddr)); 

    if (sockconnect == 0){
        printf("[+] Connected successfully to 127.0.0.1:9999.\n");
    }

	char* message = malloc(255*sizeof(char));

	int messagebytes = recv(sockfd, message, 255, 0); 

    if (messagebytes != -1){

        printf("[+] Received %d bytes\n",messagebytes);

    }

	printf("[+] The message is: %s\n",message);

	free(message);

    return 0;
}