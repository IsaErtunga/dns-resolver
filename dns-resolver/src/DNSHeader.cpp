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
    // 0xFFFF is the maximum two byte hex value
    return  id <= 0xFFFF &&
            flags <= 0xFFFF &&
            numQuestions <= 0xFFFF &&
            numAnswers <= 0xFFFF &&
            numAuthorities <= 0xFFFF &&
            numAdditionals <= 0xFFFF;
}

std::string DNSHeader::HeaderToBytes() {
    std::string bytes;
    std::array<char, 5> res;
    
    // convert fields to 2 2-byte integer in hex format
    // append to bytes string
    sprintf(&res[0], "%04x", this->id);
    bytes += {'\\', 'x', res[0], res[1], '\\', 'x', res[2], res[3]};
    sprintf(&res[0], "%04x", this->flags);
    bytes += {'\\', 'x', res[0], res[1], '\\', 'x', res[2], res[3]};
    sprintf(&res[0], "%04x", this->numQuestions);
    bytes += {'\\', 'x', res[0], res[1], '\\', 'x', res[2], res[3]};
    sprintf(&res[0], "%04x", this->numAnswers);
    bytes += {'\\', 'x', res[0], res[1], '\\', 'x', res[2], res[3]};
    sprintf(&res[0], "%04x", this->numAuthorities);
    bytes += {'\\', 'x', res[0], res[1], '\\', 'x', res[2], res[3]};
    sprintf(&res[0], "%04x", this->numAdditionals);
    bytes += {'\\', 'x', res[0], res[1], '\\', 'x', res[2], res[3]};
    
    return bytes;
}
