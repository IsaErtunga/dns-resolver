#ifndef DNSQuestion_hpp
#define DNSQuestion_hpp

#include <vector>

class DNSQuestion {
private:
    uint16_t type;
    uint16_t klass;
    std::vector<uint8_t> name;
    
public:
    DNSQuestion() {};
    DNSQuestion(uint16_t type, uint16_t klass, std::vector<uint8_t> name);
    std::vector<uint8_t> ToBytes();
};

#endif /* DNSQuestion_hpp */
