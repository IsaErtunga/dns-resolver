#ifndef DNSRecord_hpp
#define DNSRecord_hpp

#include <cstdint>
#include <vector>

class DNSRecord {
private:
    std::vector<uint8_t> name;
    std::vector<uint8_t> data;
    int type;
    int klass;
    int ttl;
    
public:
    DNSRecord();
};

#endif /* DNSRecord_hpp */
