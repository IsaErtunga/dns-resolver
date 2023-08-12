#include "src/DNSQueryBuilder.hpp"
#include "src/Socket.hpp"

int main(int argc, const char* argv[]) {
    srand((unsigned int) std::time(nullptr));
    
    Socket socket{53, "8.8.8.8"};
    std::vector<uint8_t> query = BuildQuery("www.example.com", TYPE_A);
    std::vector<unsigned char> resp = socket.SendAndReceive(query);
    
    ParseResponse(resp);
    
    std::cout << std::endl;
    return 0;
}
