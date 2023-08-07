#ifndef DNSQuestion_hpp
#define DNSQuestion_hpp

#include <vector>

class DNSQuestion {
private:
    int type;
    int klass;
    std::vector<uint8_t> name;
    
public:
    DNSQuestion(int type, int klass, std::vector<uint8_t> name);
};

#endif /* DNSQuestion_hpp */
