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

// https://datatracker.ietf.org/doc/html/rfc1035#section-4.1.4
DNSRecord DNSRecord::FromBytes(std::vector<uint8_t> bytes,
                               std::vector<uint8_t>::iterator& it,
                               std::vector<uint8_t> (*decodeName)(std::vector<uint8_t>, std::vector<uint8_t>::iterator&)) {
    std::vector<uint8_t> name = decodeName(bytes, it);
    std::vector<uint8_t> data;
    uint16_t type     = static_cast<uint16_t>((*it << 8) | *it+1); it += 2;
    uint16_t klass    = static_cast<uint16_t>((*it << 8) | *it+1); it += 2;
    uint16_t ttl      = static_cast<uint16_t>((*it << 8) | *it+1); it += 2;
    uint16_t dataLen  = static_cast<uint16_t>((*it << 8) | *it+1); it += 2;
    
    for (int i = 0; i < dataLen + 1; i++) {
        data.push_back(*(it++));
        data.push_back(*(it++));
    }
    
    // std::cout << "type: " << type << "\n";
    // std::cout << "klass: " << klass << "\n";
    // std::cout << "ttl: " << ttl << "\n";
    // std::cout << "dataLen: " << dataLen << "\n";
    // for (const auto& n : data) {
    //     std::cout << (unsigned)n << ".";
    // }
    
    return DNSRecord{
        name,
        data,
        type,
        klass,
        ttl,
    };
}

std::vector<uint8_t> DNSRecord::GetData() {
    return this->data;
}
