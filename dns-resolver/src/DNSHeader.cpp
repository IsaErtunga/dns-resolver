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
    
    // Convert fields to 2 2-byte integer in hex format
    // Append to bytes string
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

std::vector<uint16_t> DNSHeader::HeaderToBytes2() {
    // Convert fields to 2 2-byte integers in hex format
    // Bit-shift to get higher-order and lower-order bytes
    // Masking with 0xFFFF is not really necessary
    return std::vector<uint16_t> {
        static_cast<uint16_t>((this->id >> 16) & 0xFFFF),
        static_cast<uint16_t>(this->id & 0xFFFF),
        static_cast<uint16_t>((this->flags >> 16) & 0xFFFF),
        static_cast<uint16_t>(this->flags & 0xFFFF),
        static_cast<uint16_t>((this->numQuestions >> 16) & 0xFFFF),
        static_cast<uint16_t>(this->numQuestions & 0xFFFF),
        static_cast<uint16_t>((this->numAnswers >> 16) & 0xFFFF),
        static_cast<uint16_t>(this->numAnswers & 0xFFFF),
        static_cast<uint16_t>((this->numAuthorities >> 16) & 0xFFFF),
        static_cast<uint16_t>(this->numAuthorities & 0xFFFF),
        static_cast<uint16_t>((this->numAdditionals >> 16) & 0xFFFF),
        static_cast<uint16_t>(this->numAdditionals & 0xFFFF),
    };
}
