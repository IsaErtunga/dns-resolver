#include "DNSHeader.hpp"

DNSHeader::DNSHeader(int id, int flags, int numQuestions, int numAnswers, int numAuthorities, int numAdditionals) {
    if (!this->validateParams(id, flags, numQuestions, numAnswers, numAuthorities, numAdditionals)) {
        throw std::invalid_argument("invalid DNS header parameter");
    }
    
    this->id = id;
    this->flags = flags;
    this->numQuestions = numQuestions;
    this->numAnswers = numAnswers;
    this->numAuthorities = numAuthorities;
    this->numAdditionals = numAdditionals;
}

bool DNSHeader::validateParams(int id, int flags, int numQuestions, int numAnswers, int numAuthorities, int numAdditionals) {
    // 0xFFFF is the maximum two byte hex value and is equal to 65535
    return  id <= 0xFFFF &&
            flags <= 0xFFFF &&
            numQuestions <= 0xFFFF &&
            numAnswers <= 0xFFFF &&
            numAuthorities <= 0xFFFF &&
            numAdditionals <= 0xFFFF;
}

std::vector<uint8_t> DNSHeader::ToBytes() {
    return std::vector<uint8_t> {
        static_cast<uint8_t>((this->id >> 8) & 0xFF),
        static_cast<uint8_t>(this->id & 0xFF),
        static_cast<uint8_t>((this->flags >> 8) & 0xFF),
        static_cast<uint8_t>(this->flags & 0xFF),
        static_cast<uint8_t>((this->numQuestions >> 8) & 0xFF),
        static_cast<uint8_t>(this->numQuestions & 0xFF),
        static_cast<uint8_t>((this->numAnswers >> 8) & 0xFF),
        static_cast<uint8_t>(this->numAnswers & 0xFF),
        static_cast<uint8_t>((this->numAuthorities >> 8) & 0xFF),
        static_cast<uint8_t>(this->numAuthorities & 0xFF),
        static_cast<uint8_t>((this->numAdditionals >> 8) & 0xFF),
        static_cast<uint8_t>(this->numAdditionals & 0xFF),
    };
}
