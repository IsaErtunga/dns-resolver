#include "src/DNSQueryBuilder.hpp"
#include "src/Socket.hpp"

int main(int argc, const char* argv[]) {
    srand((unsigned int) std::time(nullptr));
    
    std::vector<uint8_t> query = BuildQuery("www.example.com", TYPE_A);
    
    Socket socket{53, "8.8.8.8"};
    std::vector<char> res = socket.SendAndReceive(query);
    std::cout << std::endl;
    return 0;
}
