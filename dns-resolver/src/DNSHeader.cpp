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

std::vector<uint16_t> DNSHeader::HeaderToBytes() {
    // Represents byte array
    // Converts to unsigned 16-bit integers
    return std::vector<uint16_t> {
        static_cast<uint16_t>(this->id),
        static_cast<uint16_t>(this->flags),
        static_cast<uint16_t>(this->numQuestions),
        static_cast<uint16_t>(this->numAnswers),
        static_cast<uint16_t>(this->numAuthorities),
        static_cast<uint16_t>(this->numAdditionals),
    };
}
