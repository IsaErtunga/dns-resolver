#include "DNSQuestion.hpp"

DNSQuestion::DNSQuestion(int type, int klass, std::vector<uint8_t> name) {
    this->type = type;
    this->klass = klass;
    this->name = name;
}
