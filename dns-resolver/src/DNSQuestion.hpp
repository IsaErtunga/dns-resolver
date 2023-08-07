#ifndef DNSQuestion_hpp
#define DNSQuestion_hpp

#include <vector>

class DNSQuestion {
private:
    int type;
    int klass;
    std::vector<uint16_t> name;
    
public:
    DNSQuestion() {};
    DNSQuestion(int type, int klass, std::vector<uint16_t> name);
    std::vector<uint16_t> QuestionToBytes();
};

#endif /* DNSQuestion_hpp */
