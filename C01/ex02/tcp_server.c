#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int server_fd;
    int client_fd;
    struct sockaddr_in info;
    socklen_t   addrlen;
    char    *buf[1024];
    int reciver;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        perror("EXIT");
        exit(EXIT_FAILURE);
    }
    info.sin_family = AF_INET;
    info.sin_port = htons(3000);
    info.sin_addr.s_addr = INADDR_ANY;
    bind(server_fd, (struct sockaddr *)&info, sizeof(info));
    listen(server_fd, 0);
    addrlen = sizeof(info);
    client_fd = accept(server_fd, (struct sockaddr *)&info, &addrlen);
}