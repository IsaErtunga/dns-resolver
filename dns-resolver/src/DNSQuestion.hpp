#ifndef DNSQuestion_hpp
#define DNSQuestion_hpp

#include <vector>

class DNSQuestion {
private:
    int type;
    int klass;
    std::vector<unsigned char> name;
    
public:
    DNSQuestion();
};

#endif /* DNSQuestion_hpp */
