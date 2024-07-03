#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


#define PORT 8080
#define BUFFER_SIZE 1024


struct sockaddr_in {
    short sin_family; // Address family, AF_INET
    unsigned short sin_port; // Port number, htons() is used to convert to network byte order
    struct in_addr sin_addr; // IP address, struct in_addr is used to represent IPv4 addresses
    char sin_zero[8]; // Padding to make structure the same size as struct sockaddr
};
