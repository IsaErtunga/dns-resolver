#ifndef QueryHandler_hpp
#define QueryHandler_hpp

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <iomanip>
#include <time.h>
#include <bitset>

#include "DNSHeader.hpp"
#include "DNSQuestion.hpp"
#include "DNSRecord.hpp"
#include "DNSPacket.hpp"

enum RecordType : uint16_t {
    A = 1,
};

enum RecordClass : uint16_t {
    IN = 1,
};

    
void printHex(uint32_t val);
std::vector<std::string> split(std::string str, std::string del);
std::vector<uint8_t> encodeDnsName(std::string domainName);
std::vector<uint8_t> BuildQuery(std::string dnsName, RecordType recordType);
std::vector<uint8_t> decodeDomainName(std::vector<uint8_t> resp, std::vector<uint8_t>::iterator& it);
DNSPacket ParseResponse(std::vector<unsigned char> resp);

#endif /* QueryHandler_hpp */
