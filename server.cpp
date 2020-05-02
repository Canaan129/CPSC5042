#include <cstdio>


// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

//#define PORT 8080
#define PORT 12016//port number老师给我们everyone has a unique port numeber
int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = { 0 };
    char *hello = "Hello from server";
    printf("Hello world\n");
    // Creating socket file descriptor 不改，直接用？（27-57 不用改）
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    printf("Got Socket\n");
    // Forcefully attaching socket to the port 8080 不改，直接用
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080 基本不用改
    printf("About to bind\n");
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("Waiting");
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t*)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    printf("Accepted Connected");

    // We will read the very simple HELLO message and return a Hello message back

    valread = read(new_socket, buffer, 1024);
    printf("%s\n", buffer);
    // What RPC is it
    // Parse out arguments
    // Call the correct RPC Function

    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    return 0;
}


