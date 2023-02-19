#ifndef CSCI6708_IP_H
#define CSCI6708_IP_H

#include <string>
#include <utility>
#include <array>
#include <sstream>
#include <string>
#include <bitset>
#include <cstdint>

namespace std_acl{
    constexpr uint8_t bits{8u};

class ip{
    using ip_t =  std::array<std::pair<std::bitset<bits>, std::bitset<bits>>, 4>;
    ip_t ip_data;
    ip_t get_data();
    public:
    ip(std::string ip_addr, std::string mask = "0.0.0.0"): ip_data(split(ip_addr, mask)){}
    ip_t split(std::string, std::string mask);
    bool operator==(std::string);
};

}

#endif