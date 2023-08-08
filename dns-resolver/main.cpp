#include "src/DNSQueryBuilder.hpp"
#include "src/socket.hpp"

int main(int argc, const char* argv[]) {
    srand((unsigned int) std::time(nullptr));
    
    std::vector<uint8_t> query = BuildQuery("www.example.com", 1);
    std::cout << std::endl;
    
    Socket socket{8080};
    socket.SendAndReceive();
    return 0;
}
