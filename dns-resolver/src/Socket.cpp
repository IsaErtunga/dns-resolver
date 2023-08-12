#include "Socket.hpp"

Socket::Socket(uint16_t port, const char* ip) {
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
    if (inet_pton(AF_INET, ip, &serverAdress.sin_addr) <= 0) {
        std::cerr << "Invalid ipv4 address" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    int conn = connect(socketFd, (const struct sockaddr*)&serverAdress, sizeof(serverAdress));
    if (conn < 0) {
        std::cerr << "Socket connection failed" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    this->socketFd = socketFd;
}

Socket::~Socket() {
    // close socket connection
    close(this->socketFd);
}

std::vector<unsigned char> Socket::SendAndReceive(std::vector<uint8_t> msg) {
    std::vector<unsigned char> buf(1024);
    std::string msgStr{msg.begin(), msg.end()};
    if (send(this->socketFd, msgStr.data(), msgStr.size(), 0) < 0) {
        std::cerr << "Could not send message" << std::endl;
        return buf;
    }
    read(this->socketFd, buf.data(), buf.size());
    return buf;
}
