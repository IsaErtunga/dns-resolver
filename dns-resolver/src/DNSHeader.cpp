#include "DNSHeader.hpp"

DNSHeader::DNSHeader(uint16_t id, uint16_t flags, uint16_t qdCount, uint16_t anCount, uint16_t nsCount, uint16_t arCount) {
    this->id = id;
    this->flags = flags;
    this->qdCount = qdCount;
    this->anCount = anCount;
    this->nsCount = nsCount;
    this->arCount = arCount;
}

DNSHeader DNSHeader::FromBytes(std::vector<uint8_t>::iterator& it) {
    // 0,  1  -> id
    // 2,  3  -> flags
    // 4,  5  -> numQuestions
    // 6,  7  -> numAnswers
    // 8,  9  -> numAuthorities
    // 10, 11 -> numAdditionals
    uint16_t id      = static_cast<uint16_t>((*it << 8) | *it+1); it += 2;
    uint16_t flags   = static_cast<uint16_t>((*it << 8) | *it+1); it += 2;
    uint16_t qdCount = static_cast<uint16_t>((*it << 8) | *it+1); it += 2;
    uint16_t anCount = static_cast<uint16_t>((*it << 8) | *it+1); it += 2;
    uint16_t nsCount = static_cast<uint16_t>((*it << 8) | *it+1); it += 2;
    uint16_t arCount = static_cast<uint16_t>((*it << 8) | *it+1); it += 2;
    return DNSHeader{
        id,
        flags,
        qdCount,
        anCount,
        nsCount,
        arCount,
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
        static_cast<uint8_t>((this->qdCount >> 8) & 0xFF),
        static_cast<uint8_t>(this->qdCount & 0xFF),
        static_cast<uint8_t>((this->anCount >> 8) & 0xFF),
        static_cast<uint8_t>(this->anCount & 0xFF),
        static_cast<uint8_t>((this->nsCount >> 8) & 0xFF),
        static_cast<uint8_t>(this->nsCount & 0xFF),
        static_cast<uint8_t>((this->arCount >> 8) & 0xFF),
        static_cast<uint8_t>(this->arCount & 0xFF),
    };
}

uint16_t DNSHeader::GetId() {
    return this->id;
}

uint16_t DNSHeader::GetFlags() {
    return this->flags;
}

uint16_t DNSHeader::GetQdCount() {
    return this->qdCount;
}

uint16_t DNSHeader::GetAnCount() {
    return this->anCount;
}

uint16_t DNSHeader::GetNsCount() {
    return this->nsCount;
}

uint16_t DNSHeader::GetArCount() {
    return this->arCount;
}
