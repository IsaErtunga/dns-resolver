#include "src/DNSQueryBuilder.hpp"
#include "src/Socket.hpp"
#include "src/DNSPacket.hpp"

int main(int argc, const char* argv[]) {
    srand((unsigned int) std::time(nullptr));
    
    Socket socket{53, "8.8.8.8"};
    std::vector<uint8_t> query = BuildQuery("example.com", RecordType::A);
    std::vector<unsigned char> resp = socket.SendAndReceive(query);
    
    DNSPacket packet = ParseResponse(resp);
    for (const auto& i : packet.GetAnswers()[0].GetData()) {
        std::cout << (unsigned)i << ".";
    }
    
    std::cout << std::endl;
    return 0;
}
