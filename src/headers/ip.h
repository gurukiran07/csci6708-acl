#ifndef CSCI6708_IP_H
#define CSCI6708_IP_H

#include <string>
#include <utility>
#include <array>
#include <sstream>
#include <string>

namespace std_acl{

class ip{
    std::array<std::pair<int, bool>, 4> ip_data{};
    auto get_data();
    public:
    ip(std::string ip_addr, std::string mask = "0.0.0.0"): ip_data(split(ip_addr, mask)){}
    std::array<std::pair<int, bool>, 4> split(std::string, std::string mask);
    bool operator==(std::string);
};

}

#endif