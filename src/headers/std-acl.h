#ifndef CSCI6708_STDACL_H
#define CSCI6708_STDACL_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include "ip.h"

namespace std_acl{
constexpr const char pckt_denied[7] = "denied";
constexpr const char pckt_permitted[10] = "permitted";
class acl{
    using acl_stmts_t = std::vector<std::pair<std::string, ip>>;
    acl_stmts_t acl_stmts;
    std::vector<std::string> comp_ips;
    public:
    acl(){}
    acl(std::string acl_file, std::string ip_file)
        :acl_stmts(read_acl_file(acl_file)), comp_ips(read_ip_file(ip_file)){}

    acl_stmts_t read_acl_file(std::string);
    std::vector<std::string> read_ip_file(std::string);
    void process();
};
};

#endif