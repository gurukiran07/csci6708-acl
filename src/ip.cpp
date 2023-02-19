#include "ip.h"
#include <iostream>
namespace std_acl{
ip::ip_t ip::split(std::string ip_addr, std::string mask){
    ip::ip_t ip_data{};
    std::stringstream ip_split(ip_addr), mask_split(mask);
    std::string ip_byte, mask_byte;
    int count{0};

    while(std::getline(ip_split, ip_byte, '.') && std::getline(mask_split, mask_byte, '.')){
        ip_data[count].first = std::stoul(ip_byte);
        ip_data[count].second = std::stoul(mask_byte);
        ++count;
    }
    return ip_data;
}

ip::ip_t ip::get_data(){
    return ip_data;
}

bool ip::operator==(std::string ip_addr){
    ip::ip_t comp_ip = ip(ip_addr).get_data();
    bool flag{true};
    for(size_t i = 0; i < comp_ip.size(); ++i){
        auto byte = ip_data[i];
        auto comp_byte = comp_ip[i];
        auto tmp_msk = byte.first | byte.second;
        auto cmp_msk = comp_byte.first | byte.second;
        flag &= (tmp_msk == cmp_msk);
    }
    return flag;
}
}