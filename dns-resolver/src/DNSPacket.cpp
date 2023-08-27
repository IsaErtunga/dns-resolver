#include "DNSPacket.hpp"

DNSPacket::DNSPacket(DNSHeader header,
                     std::vector<DNSQuestion> questions,
                     std::vector<DNSRecord> answers,
                     std::vector<DNSRecord> authorities,
                     std::vector<DNSRecord> additionals) {
    this->header = header;
    this->questions = questions;
    this->answers = answers;
    this->authorities = authorities;
    this->additionals = additionals;
}

std::vector<DNSQuestion> DNSPacket::GetQuestions() {
    return this->questions;
}

std::vector<DNSRecord> DNSPacket::GetAnswers() {
    return this->answers;
}

std::vector<DNSRecord> DNSPacket::GetAuthorities() {
    return this->authorities;
}

std::vector<DNSRecord> DNSPacket::GetAdditionals() {
    return this->additionals;
}
