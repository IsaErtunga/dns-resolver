#include "src/DNSHeader.hpp"

int main(int argc, const char* argv[]) {
    DNSHeader h(0x1314, 0, 1, 0, 0, 0);
    std::cout << h.HeaderToBytes();
    return 0;
}
