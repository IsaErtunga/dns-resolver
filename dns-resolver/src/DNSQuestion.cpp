#include "DNSQuestion.hpp"

DNSQuestion::DNSQuestion(uint16_t type, uint16_t klass, std::vector<uint8_t> name) {
    this->type = type;
    this->klass = klass;
    this->name = name;
}

DNSQuestion DNSQuestion::FromBytes(std::vector<uint8_t> bytes,
                                   std::vector<uint8_t>::iterator& it,
                                   std::vector<uint8_t> (*decodeName)(std::vector<uint8_t> resp, std::vector<uint8_t>::iterator& it)) {
    std::vector<uint8_t> name = decodeName(bytes, it);
    uint16_t type  = static_cast<uint16_t>((*it << 8) | *it+1); it += 2;
    uint16_t klass = static_cast<uint16_t>((*it << 8) | *it+1); it += 2;
    return DNSQuestion{
        type,
        klass,
        name,
    };
}

std::vector<uint8_t> DNSQuestion::ToBytes() {
    std::vector<uint8_t> qb{this->name.begin(), this->name.end()};
    qb.push_back(static_cast<uint8_t>((this->type >> 8) & 0xFF));
    qb.push_back(static_cast<uint8_t>(this->type));
    qb.push_back(static_cast<uint8_t>((this->klass >> 8) & 0xFF));
    qb.push_back(static_cast<uint8_t>(this->klass));
    return qb;
}
