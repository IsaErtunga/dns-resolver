#include "DNSQuestion.hpp"

DNSQuestion::DNSQuestion(int type, int klass, std::vector<uint16_t> name) {
    this->type = type;
    this->klass = klass;
    this->name = name;
}

std::vector<uint16_t> DNSQuestion::QuestionToBytes() {
    return std::vector<uint16_t>{
        static_cast<uint16_t>(this->type),
        static_cast<uint16_t>(this->klass),
    };
}
