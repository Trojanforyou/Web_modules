#include <sys/socket.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>


int main(int ac, char **av)
{
    int fd;
    struct sockaddr_in info;
    int con;
    char buf[1024] = "hello";
    
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd <= 0)
    {
        perror("FD:");
        exit(EXIT_FAILURE);
    }
    con = inet_pton(AF_INET, "127.0.0.1", &info.sin_addr);
    if (con <= 0)
    {
        perror("Connection");
        exit(EXIT_FAILURE);
    }
    info.sin_family = AF_INET;
    info.sin_port = htons(2000);
    connect(fd, (struct sockaddr *)&info, sizeof(struct sockaddr_in));
    int sent = send(fd, buf, strlen(buf), 0);
    // ssize_t sent = sendto(fd, buf, strlen(buf), 0, (struct sockaddr *)&info, sizeof(info));
    // if (sent == -1)
    //     perror("sendto");
    // else
    //     printf("Sent %zd bytes\n", sent);

}