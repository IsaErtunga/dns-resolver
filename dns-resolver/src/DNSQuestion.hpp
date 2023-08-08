#ifndef DNSQuestion_hpp
#define DNSQuestion_hpp

#include <vector>

class DNSQuestion {
private:
    int type;
    int klass;
    std::vector<uint8_t> name;
    
public:
    DNSQuestion() {};
    DNSQuestion(int type, int klass, std::vector<uint8_t> name);
    std::vector<uint8_t> ToBytes();
};

#endif /* DNSQuestion_hpp */
