#include "src/DNSQueryBuilder.hpp"

int main(int argc, const char* argv[]) {
    srand((unsigned int) std::time(nullptr));
    
    BuildQuery("www.example.com", 1);
    std::cout << std::endl;
    return 0;
}
