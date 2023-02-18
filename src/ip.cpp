#include <string>
#include <utility>
#include <array>
#include <sstream>
#include <string>
#include "ip.h"

namespace std_acl{
std::array<std::pair<int, bool>, 4> ip::split(std::string ip_addr, std::string mask){
    std::array<std::pair<int, bool>, 4> ip_data{};
    std::stringstream ip_split(ip_addr);
    std::stringstream mask_split(mask);
    std::string ip_byte;
    std::string mask_byte;
    int count{0};

    while(std::getline(ip_split, ip_byte, '.') and std::getline(mask_split, mask_byte, '.')){
        ip_data[++count].first = std::stoi(ip_byte);
        ip_data[count].second = mask_byte == "0";
    }
    return ip_data;
}

bool ip::operator==(std::string ip_addr){
    auto comp_ip = split(ip_addr);
    bool flag{true};
    for(size_t i = 0; i < comp_ip.size(); ++i){
        auto ip_pair = ip_data[i];
        auto comp_ip_pair = comp_ip[i];
        if (ip_pair.second){
            flag &= (ip_pair.first == comp_ip_pair.first);
        }
    }
    return flag;
}
}