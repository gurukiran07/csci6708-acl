#ifndef CSCI6708_IP_H
#define CSCI6708_IP_H

#include <string>
#include <utility>
#include <array>
#include <sstream>
#include <string>
#include <bitset>
#include <cstdint>
#include <unordered_set>

namespace std_acl
{
    constexpr uint8_t bits{8u};
    constexpr const char pckt_denied[7] = "denied";
    constexpr const char pckt_permitted[10] = "permitted";

    class ip
    {
        using ip_t = std::array<std::pair<std::bitset<bits>, std::bitset<bits>>, 4>;
        ip_t ip_data;
        std::unordered_set<size_t> ports;
        ip_t get_data();

    public:
        std::string ip_repr;
        ip() {}
        ip(std::string ip_addr, std::string mask = "0.0.0.0") : ip_data(split(ip_addr, mask)),
                                                                ports{},
                                                                ip_repr(ip_addr) {}

        void set_ports(std::string port_num);
        std::unordered_set<size_t> get_ports();
        ip_t split(std::string, std::string mask);
        bool operator==(ip);
    };

}

#endif