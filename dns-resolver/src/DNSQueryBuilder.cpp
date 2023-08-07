#include "DNSQueryBuilder.hpp"

std::vector<uint16_t> encodeDnsName(std::string domainName) {
    std::vector<uint16_t> encoded;
    std::vector<std::string> domainNameSplit = split(domainName, ".");
    
    // Stores length of the word,
    // followed by the ASCII code of each char in the word in hex.
    // google.com -> \x06\x67\x6f\x6f\x67\x6c\x65\x03\x63\x6f\x6d\x00
    for (const auto& word : domainNameSplit) {
        encoded.push_back(static_cast<uint16_t>(word.size()));
        
        for (unsigned char c : word) {
            encoded.push_back(static_cast<uint16_t>(c));
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
    std::cout << "\\x" << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(val);
}

int TYPE_A = 1;
int CLASS_IN = 1;

void BuildQuery(std::string dnsName, int recordType) {
    std::vector<uint16_t> nameBytes = encodeDnsName(dnsName);
    int id = rand() % 65535;
    int recur = 1 << 8;
    
    DNSHeader header(id, recur, 1, 0, 0, 0);
    DNSQuestion question(recordType, CLASS_IN, nameBytes);
    
    std::vector<uint16_t> headerBytes = header.HeaderToBytes();
    std::vector<uint16_t> questionBytes = question.QuestionToBytes();
    for (const auto& el : questionBytes) {
        std::cout << el << ", ";
    }
}
