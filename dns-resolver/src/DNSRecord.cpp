#include "DNSRecord.hpp"

DNSRecord::DNSRecord(std::vector<uint8_t> name,
                     std::vector<uint8_t> data,
                     uint16_t type,
                     uint16_t klass,
                     uint16_t ttl) {
    this->name = name;
    this->data = data;
    this->type = type;
    this->klass = klass;
    this->ttl = ttl;
}

void DNSRecord::FromBytes(std::vector<uint8_t> bytes) {
    
}
