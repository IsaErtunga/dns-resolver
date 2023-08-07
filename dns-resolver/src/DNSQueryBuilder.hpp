#ifndef DNSQueryBuilder_hpp
#define DNSQueryBuilder_hpp

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <iomanip>
#include <time.h>

std::vector<std::string> split(std::string str, std::string del);
std::vector<uint8_t> encodeDnsName(std::string domainName);
void printHex(uint32_t val);
void buildQuery(std::string dnsName, int recordType);

#endif /* DNSQueryBuilder_hpp */
