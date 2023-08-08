#ifndef DNSHeader_hpp
#define DNSHeader_hpp

#include <iostream>
#include <vector>
#include <array>
#include <stdexcept>

class DNSHeader {
private:
    int id;
    int flags;
    int numQuestions = 0;
    int numAnswers = 0;
    int numAuthorities = 0;
    int numAdditionals = 0;
    
    bool validateParams(int id, int flags, int numQuestions, int numAnswers, int numAuthorities, int numAdditionals);
    
public:
    DNSHeader() {};
    DNSHeader(int id, int flags, int numQuestions, int numAnswers, int numAuthorities, int numAdditionals);
    std::vector<uint8_t> ToBytes();
};

#endif /* DNSHeader_hpp */
