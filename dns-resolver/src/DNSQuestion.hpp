#ifndef DNSQuestion_hpp
#define DNSQuestion_hpp

#include <vector>

class DNSQuestion {
public:
    std::vector<unsigned char> Name;
    int Type;
    int Class;
};

#endif /* DNSQuestion_hpp */
