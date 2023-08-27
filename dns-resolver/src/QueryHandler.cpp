#include "QueryHandler.hpp"

std::vector<uint8_t> encodeDomainName(std::string domainName) {
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
    std::vector<uint8_t> nameBytes = encodeDomainName(dnsName);
    uint16_t id = rand() % 65535;
    // uint16_t recur = 1 << 8;
    
    DNSHeader header{id, 0, 1, 0, 0, 0};
    DNSQuestion question{recordType, RecordClass::IN, nameBytes};

    std::vector<uint8_t> headerBytes = header.ToBytes();
    std::vector<uint8_t> questionBytes = question.ToBytes();
    std::vector<uint8_t> queryBytes{headerBytes.begin(), headerBytes.end()};
    for (const auto& qb : questionBytes) {
        queryBytes.push_back(qb);
    }
    return queryBytes;
}

std::vector<uint8_t> decodeDomainName(std::vector<uint8_t> resp, std::vector<uint8_t>::iterator& it) {
    // Decodes DNS names by taking compression into account
    // Reads response bytes. Look for length byte which starts with 11
    // Extract the offset pointer and inturn the bytes building the name
    std::vector<uint8_t> name;
    while (*it != 0) {
        if (*it > 63) {
            // Last 6 bits + next byte as pointer
            int offset = (*it & 0x3F) + *(++it);
            int end = offset + resp[offset] + 1;
            int ptr = offset;
            while (resp[ptr] != 0) {
                ptr++;
                if (ptr == end) {
                    if (resp[ptr] == 0) {
                        break;
                    }
                    end = end + resp[ptr] + 1;
                    continue;
                }
                name.push_back(resp[ptr]);
            }
            it += 2;
            break;
        } else {
            int end = static_cast<int>(*it);
            for (int i = 0; i < end; i++) {
                it++;
                name.push_back(*it);
            }
        }
        it++;
    }
    
    it++;
    return name;
}

DNSPacket ParseResponse(std::vector<unsigned char> resp) {
    std::vector<uint8_t>::iterator it = resp.begin();
    DNSHeader header = DNSHeader::FromBytes(it);
    std::vector<DNSQuestion> questions;
    std::vector<DNSRecord> answers;
    std::vector<DNSRecord> authorities;
    std::vector<DNSRecord> additionals;
    int i;
    for (i = 0; i < header.GetQdCount(); i++) {
        questions.push_back(DNSQuestion::FromBytes(resp, it, &decodeDomainName));
    }
    
    for (i = 0; i < header.GetAnCount(); i++) {
        answers.push_back(DNSRecord::FromBytes(resp, it, &decodeDomainName));
    }

    for (i = 0; i < header.GetNsCount(); i++) {
        authorities.push_back(DNSRecord::FromBytes(resp, it, &decodeDomainName));
    }
    
    for (i = 0; i < header.GetArCount(); i++) {
        additionals.push_back(DNSRecord::FromBytes(resp, it, &decodeDomainName));
    }
    
    return DNSPacket{
        header,
        questions,
        answers,
        authorities,
        additionals
    };
}
