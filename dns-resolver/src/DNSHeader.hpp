#ifndef DNSHeader_hpp
#define DNSHeader_hpp

#include <iostream>
#include <vector>
#include <array>
#include <stdexcept>
#include <cstdint>

class DNSHeader {
private:
    uint16_t id;
    uint16_t flags;
    uint16_t numQuestions = 0;
    uint16_t numAnswers = 0;
    uint16_t numAuthorities = 0;
    uint16_t numAdditionals = 0;
    
public:
    DNSHeader() {};
    DNSHeader(uint16_t id, uint16_t flags, uint16_t numQuestions, uint16_t numAnswers, uint16_t numAuthorities, uint16_t numAdditionals);
    static DNSHeader FromBytes(std::vector<uint8_t> bytes);
    std::vector<uint8_t> ToBytes();
};

#endif /* DNSHeader_hpp */
