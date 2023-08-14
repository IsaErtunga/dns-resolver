#ifndef DNSHeader_hpp
#define DNSHeader_hpp

#include <iostream>
#include <vector>
#include <array>
#include <stdexcept>
#include <cstdint>

class DNSHeader {
private:
    // https://datatracker.ietf.org/doc/html/rfc1035#section-4.1.1
    uint16_t id;
    uint16_t flags;
    uint16_t qdCount = 0;
    uint16_t anCount = 0;
    uint16_t nsCount = 0;
    uint16_t arCount = 0;
    
public:
    DNSHeader() {};
    DNSHeader(uint16_t id, uint16_t flags, uint16_t qdCount, uint16_t anCount, uint16_t nsCount, uint16_t arCount);
    static DNSHeader FromBytes(std::vector<uint8_t>::iterator& it);
    std::vector<uint8_t> ToBytes();
    uint16_t GetId();
    uint16_t GetFlags();
    uint16_t GetQdCount();
    uint16_t GetAnCount();
    uint16_t GetNsCount();
    uint16_t GetArCount();
};

#endif /* DNSHeader_hpp */
