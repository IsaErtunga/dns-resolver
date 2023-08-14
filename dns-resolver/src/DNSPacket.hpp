#ifndef DNSPacket_hpp
#define DNSPacket_hpp

#include <vector>

#include "DNSHeader.hpp"
#include "DNSQuestion.hpp"
#include "DNSRecord.hpp"

class DNSPacket {
private:
    DNSHeader header;
    std::vector<DNSQuestion> questions;
    std::vector<DNSRecord> answers;
    std::vector<DNSRecord> authorities;
    std::vector<DNSRecord> additionals;

public:
    DNSPacket(DNSHeader header,
              std::vector<DNSQuestion> questions,
              std::vector<DNSRecord> answers,
              std::vector<DNSRecord> authorities,
              std::vector<DNSRecord> additionals);
    std::vector<DNSQuestion> GetQuestions();
    std::vector<DNSRecord> GetAnswers();
    std::vector<DNSRecord> GetAuthoroties();
    std::vector<DNSRecord> GetAdditionals();
};

#endif /* DNSPacket_hpp */
