#ifndef CSCI6708_STDACL_H
#define CSCI6708_STDACL_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include "ip.h"

namespace std_acl{
class acl{
    using acl_stmts_t = std::vector<std::pair<std::string, ip>>;
    acl_stmts_t acl_stmts;
    std::vector<ip> comp_ips;
    public:
    acl(std::string acl_file, std::string ip_file):
        acl_stmts(read_acl_file(acl_file)),
        comp_ips(read_ip_file(ip_file)){}

    acl_stmts_t read_acl_file(std::string);
    std::vector<ip> read_ip_file(std::string);
    void process();
};
}

#endif