#ifndef socket_hpp
#define socket_hpp

#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>

class Socket {
private:
    int socketFd;
public:
    Socket(uint16_t port);
    ~Socket();
    void SendAndReceive();
};

#endif /* socket_hpp */
