#include "DNSQuestion.hpp"

DNSQuestion::DNSQuestion(uint16_t type, uint16_t klass, std::vector<uint8_t> name) {
    this->type = type;
    this->klass = klass;
    this->name = name;
}

std::vector<uint8_t> DNSQuestion::ToBytes() {
    std::vector<uint8_t> qb{this->name.begin(), this->name.end()};
    qb.push_back(static_cast<uint8_t>((this->type >> 8) & 0xFF));
    qb.push_back(static_cast<uint8_t>(this->type));
    qb.push_back(static_cast<uint8_t>((this->klass >> 8) & 0xFF));
    qb.push_back(static_cast<uint8_t>(this->klass));
    return qb;
}
