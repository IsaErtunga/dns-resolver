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
    
std::vector<uint16_t> encodeDnsName(std::string domainName);
std::vector<std::string> split(std::string str, std::string del);
void printHex(uint32_t val);
void BuildQuery(std::string dnsName, int recordType);

#endif /* DNSQueryBuilder_hpp */
