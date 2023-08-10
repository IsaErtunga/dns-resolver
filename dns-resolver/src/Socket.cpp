#include "Socket.hpp"

#define IP_PROTOCOL 0
#define LOCALHOST   "127.0.0.1"

Socket::Socket(uint16_t port) {
    int socketFd = socket(AF_INET, SOCK_DGRAM, IP_PROTOCOL);
    if (socketFd < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    // Store data for socket in unix like systems
    // Don't know if it works in windows
    // sin_family should always be AF_INET (ipv4)
    struct sockaddr_in serverAdress;
    serverAdress.sin_family = AF_INET;
    serverAdress.sin_port = htons(port);
    
    // Convert ipv4 address to binary
    if (inet_pton(AF_INET, LOCALHOST, &serverAdress.sin_addr) <= 0) {
        std::cerr << "Invalid ipv4 address" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    int status = connect(socketFd, (const struct sockaddr*)&serverAdress, sizeof(serverAdress));
    if (status < 0) {
        std::cerr << "Socket connection failed" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    this->socketFd = socketFd;
}

Socket::~Socket() {
    // close socket connection
    close(this->socketFd);
}

void Socket::SendAndReceive() {
}
