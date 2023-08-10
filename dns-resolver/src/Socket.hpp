#ifndef Socket_hpp
#define Socket_hpp

#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <vector>

class Socket {
private:
    int socketFd;
public:
    Socket(uint16_t port, const char* ip);
    ~Socket();
    std::vector<char> SendAndReceive(std::vector<uint8_t> msg);
};

#endif /* Socket_hpp */
