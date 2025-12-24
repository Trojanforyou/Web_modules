#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int ac, char **av)
{
    int set;
    int reciever;
    int server_fd;
    struct sockaddr_in  info;
    char    buf[1028];

    server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_fd <= 0)
    {
        perror("FD");
        exit(EXIT_FAILURE);
    }
    info.sin_family = AF_INET;
    info.sin_port = htons(90);
    info.sin_addr.s_addr = INADDR_ANY;
    set =  bind(server_fd, (struct sockaddr *)&info, sizeof(struct sockaddr_in));
    if (set < 0)
    {
        perror("BIND");
        exit(EXIT_FAILURE);
    }
    reciever = recv(server_fd, buf, sizeof(buf), 0);
    if (reciever == -1)
    {
        perror("RECV");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);
    close(server_fd);
}