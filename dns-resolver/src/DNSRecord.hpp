#ifndef DNSRecord_hpp
#define DNSRecord_hpp

#include <cstdint>
#include <vector>
#include <iostream>

class DNSRecord {
private:
    std::vector<uint8_t> name;
    std::vector<uint8_t> data;
    uint16_t type;
    uint16_t klass;
    uint16_t ttl;
    
public:
    DNSRecord(std::vector<uint8_t> name, std::vector<uint8_t> data, uint16_t type, uint16_t klass, uint16_t ttl);
    static DNSRecord FromBytes(std::vector<uint8_t> bytes,
                               std::vector<uint8_t>::iterator& it,
                               std::vector<uint8_t> (*decodeName)(std::vector<uint8_t>, std::vector<uint8_t>::iterator&));
    std::vector<uint8_t> GetData();
};

#endif /* DNSRecord_hpp */
