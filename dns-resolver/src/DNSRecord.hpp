#ifndef DNSRecord_hpp
#define DNSRecord_hpp

#include <cstdint>
#include <vector>
#include <iostream>
#include "DNSQueryBuilder.hpp"
#include <bitset>

class DNSRecord {
private:
    std::vector<uint8_t> name;
    std::vector<uint8_t> data;
    uint16_t type;
    uint16_t klass;
    uint16_t ttl;
    
public:
    DNSRecord(std::vector<uint8_t> name, std::vector<uint8_t> data, uint16_t type, uint16_t klass, uint16_t ttl);
    static void FromBytes(std::vector<uint8_t> bytes);
};

#endif /* DNSRecord_hpp */
