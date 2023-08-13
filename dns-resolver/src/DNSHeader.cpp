#include "DNSHeader.hpp"

DNSHeader::DNSHeader(uint16_t id, uint16_t flags, uint16_t numQuestions, uint16_t numAnswers, uint16_t numAuthorities, uint16_t numAdditionals) {
    this->id = id;
    this->flags = flags;
    this->numQuestions = numQuestions;
    this->numAnswers = numAnswers;
    this->numAuthorities = numAuthorities;
    this->numAdditionals = numAdditionals;
}

DNSHeader DNSHeader::FromBytes(std::vector<uint8_t>::iterator& it) {
    // 0,  1  -> id
    // 2,  3  -> flags
    // 4,  5  -> numQuestions
    // 6,  7  -> numAnswers
    // 8,  9  -> numAuthorities
    // 10, 11 -> numAdditionals
    uint16_t id             = static_cast<uint16_t>((*it << 8) | *it+1); it += 2;
    uint16_t flags          = static_cast<uint16_t>((*it << 8) | *it+1); it += 2;
    uint16_t numQuestions   = static_cast<uint16_t>((*it << 8) | *it+1); it += 2;
    uint16_t numAnswers     = static_cast<uint16_t>((*it << 8) | *it+1); it += 2;
    uint16_t numAuthorities = static_cast<uint16_t>((*it << 8) | *it+1); it += 2;
    uint16_t numAdditionals = static_cast<uint16_t>((*it << 8) | *it+1); it += 2;
    return DNSHeader{
        id,
        flags,
        numQuestions,
        numAnswers,
        numAuthorities,
        numAdditionals,
    };
}

std::vector<uint8_t> DNSHeader::ToBytes() {
    // Convert fields to 2 one-byte integers in hex format
    // Bit-shift to get higher-order and lower-order bytes
    return std::vector<uint8_t>{
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
