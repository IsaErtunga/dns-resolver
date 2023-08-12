#include "DNSQuestion.hpp"

DNSQuestion::DNSQuestion(uint16_t type, uint16_t klass, std::vector<uint8_t> name) {
    this->type = type;
    this->klass = klass;
    this->name = name;
}

DNSQuestion DNSQuestion::FromBytes(std::vector<uint8_t> bytes) {
    std::vector<uint8_t> name;
    unsigned int i = 0;
    unsigned int segLen = static_cast<unsigned int>(bytes[i]);
    
    // Read length descriptor amout of bytes 3www7example3com
    // Stop when descriptor is 0
    while (i < bytes.size()) {
        for (int j = i+1; j < i+segLen+1; j++) {
            name.push_back(bytes[j]);
        }
        i += segLen + 1;
        if ((segLen = static_cast<unsigned int>(bytes[i])) == 0) {
            break;
        }
        name.push_back(46); // add ASCII code for "."
    }
    
    return DNSQuestion{
        static_cast<uint16_t>((bytes[i]    << 8) | bytes[i+1]),
        static_cast<uint16_t>((bytes[i+2]  << 8) | bytes[i+3]),
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
