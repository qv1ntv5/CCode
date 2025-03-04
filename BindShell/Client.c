#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/select.h>
#include <stdbool.h>

int main() {
   
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(4444);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)); //Create a socket and connect

    printf("[+] Connected to bind shell at 127.0.0.1:4444\n");

    fcntl(0, F_SETFL, O_NONBLOCK);// Enable non-blocking mode on stdin


    // 5. Main loop: read from socket and stdin, forward data
    while (true) {
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(sockfd, &fds); // Watch socket
        FD_SET(0, &fds); // Watch keyboard input

        // Use select() to wait for activity on either stdin or the socket
        if (select(sockfd + 1, &fds, NULL, NULL, NULL) < 0) {
            perror("[-] Select error");
            break;
        }

        // Read from the socket and print to the terminal
        if (FD_ISSET(sockfd, &fds)) {
            char buffer[1024];
            int bytes = read(sockfd, buffer, sizeof(buffer) - 1);
            if (bytes <= 0) {
                printf("[-] Connection closed\n");
                break;
            }
            buffer[bytes] = '\0';
            printf("%s", buffer);
            fflush(stdout);
        }

        // Read from stdin and send to the socket
        if (FD_ISSET(0, &fds)) {
            char input[1024];
            int bytes = read(0, input, sizeof(input) - 1);
            if (bytes > 0) {
                input[bytes] = '\0';
                write(sockfd, input, bytes);
            }
        }
    }

    close(sockfd);
    return 0;
}