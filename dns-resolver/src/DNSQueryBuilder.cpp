#include "DNSQueryBuilder.hpp"

const int CLASS_IN = 1;

std::vector<uint8_t> encodeDnsName(std::string domainName) {
    std::vector<uint8_t> encoded;
    std::vector<std::string> domainNameSplit = split(domainName, ".");
    
    // Stores length of the word,
    // followed by the ASCII code of each char in the word in hex.
    // google.com -> \x06\x67\x6f\x6f\x67\x6c\x65\x03\x63\x6f\x6d\x00
    for (const auto& word : domainNameSplit) {
        encoded.push_back(static_cast<uint8_t>(word.size()));
        
        for (unsigned char c : word) {
            encoded.push_back(static_cast<uint8_t>(c));
        }
    }
    
    // Null termination
    encoded.push_back(0);
    return encoded;
}

std::vector<std::string> split(std::string str, std::string del) {
    std::vector<std::string> res;
    int start, end = -1 * del.size();
    do {
        start = end + del.size();
        end = str.find(del, start);
        res.push_back(str.substr(start, end-start));
    } while (end != -1);
    return res;
}

void printHex(uint32_t val) {
    std::cout << "\\x" << std::setw(2) << std::setfill('0') << std::hex << val;
}

std::vector<uint8_t> BuildQuery(std::string dnsName, RecordType recordType) {
    std::vector<uint8_t> nameBytes = encodeDnsName(dnsName);
    int id = rand() % 65535;
    int recur = 1 << 8;
    
    DNSHeader header{id, recur, 1, 0, 0, 0};
    DNSQuestion question{recordType, CLASS_IN, nameBytes};

    std::vector<uint8_t> headerBytes = header.ToBytes();
    std::vector<uint8_t> questionBytes = question.ToBytes();
    std::vector<uint8_t> queryBytes{headerBytes.begin(), headerBytes.end()};
    for (const auto& qb : questionBytes) {
        queryBytes.push_back(qb);
    }
    return queryBytes;
}
