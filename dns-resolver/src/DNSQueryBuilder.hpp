#ifndef DNSQueryBuilder_hpp
#define DNSQueryBuilder_hpp

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <iomanip>
#include <time.h>

#include "DNSHeader.hpp"
#include "DNSQuestion.hpp"

enum RecordType {
    TYPE_A = 1,
};
    
void printHex(uint32_t val);
std::vector<std::string> split(std::string str, std::string del);
std::vector<uint8_t> encodeDnsName(std::string domainName);
std::vector<uint8_t> BuildQuery(std::string dnsName, RecordType recordType);

#endif /* DNSQueryBuilder_hpp */
