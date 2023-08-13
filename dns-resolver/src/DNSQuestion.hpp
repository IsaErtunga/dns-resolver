#ifndef DNSQuestion_hpp
#define DNSQuestion_hpp

#include <vector>
#include <iostream>

class DNSQuestion {
private:
    uint16_t type;
    uint16_t klass;
    std::vector<uint8_t> name;
    
public:
    DNSQuestion() {};
    DNSQuestion(uint16_t type, uint16_t klass, std::vector<uint8_t> name);
    static DNSQuestion FromBytes(std::vector<uint8_t> bytes,
                                  std::vector<uint8_t>::iterator& it,
                                  std::vector<uint8_t> (*decodeName)(std::vector<uint8_t> resp, std::vector<uint8_t>::iterator& it));
    std::vector<uint8_t> ToBytes();
};

#endif /* DNSQuestion_hpp */
