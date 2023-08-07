#include "src/DNSHeader.hpp"
#include "src/DNSQuestion.hpp"
#include "src/DNSQueryBuilder.hpp"

int main(int argc, const char* argv[]) {
    srand((unsigned int) std::time(nullptr));
    
    DNSHeader header(0x1314, 0, 1, 0, 0, 0);
    std::vector<uint32_t> enc = header.HeaderToBytes3();
    for (const auto& el : enc) {
        printHex(el);
    }
    
    std::cout << std::endl;
    return 0;
}
