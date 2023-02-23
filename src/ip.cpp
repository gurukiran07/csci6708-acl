#include "ip.h"
#include <iostream>
namespace std_acl{
ip::ip_t ip::split(std::string ip_addr, std::string mask){
    mask = ip_addr == "any" ? "255.255.255.255" : mask;
    ip_addr = ip_addr == "any" ? "0.0.0.0" : ip_addr;
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

std::unordered_set<size_t> ip::get_ports(){
    return ports;
}


void ip::set_ports(std::string port_nums){
    size_t idx = port_nums.find("-");
    if (idx == std::string::npos){
        ports.insert(std::stoul(port_nums));
    }
    else{
        size_t start = std::stoul(port_nums.substr(0, idx));
        size_t end = std::stoul(port_nums.substr(idx+1, port_nums.size()));
        for(size_t i = start; i <= end; ++i){
            ports.insert(i);
        }
    }
}

bool ip::operator==(std::string ip_addr) const{
    ip comp_ip = ip(ip_addr);
    ip::ip_t comp_ip_v = comp_ip.get_data();
    bool flag{true};
    for(size_t i = 0; i < comp_ip_v.size(); ++i){
        auto byte = ip_data[i];
        auto comp_byte = comp_ip_v[i];
        auto tmp_msk = byte.first | byte.second;
        auto cmp_msk = comp_byte.first | byte.second;
        flag &= (tmp_msk == cmp_msk);
    }
    flag &= (ports == comp_ip.get_ports());
    return flag;
}

bool ip::operator==(ip comp_ip) {
    ip::ip_t comp_ip_v = comp_ip.get_data();
    bool flag{true};
    for(size_t i = 0; i < comp_ip_v.size(); ++i){
        auto byte = ip_data[i];
        auto comp_byte = comp_ip_v[i];
        auto tmp_msk = byte.first | byte.second;
        auto cmp_msk = comp_byte.first | byte.second;
        flag &= (tmp_msk == cmp_msk);
    }
    auto port = *(comp_ip.get_ports().begin());
    if (!ports.empty())
        flag &= (ports.find(port) != ports.end());
    return flag;
}
}