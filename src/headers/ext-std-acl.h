#ifndef CSCI6708_EXTENDED_ACL
#define CSCI6708_EXTENDED_ACL

#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include "ip.h"

namespace std_acl{
class ext_acl{
    using acl_stmts_t = std::vector<
                            std::pair<std::string, std::pair<ip, ip>>
                            >;
    acl_stmts_t acl_stmts;
    std::vector<std::pair<ip, ip>> comp_ips;

    public:
    ext_acl(){}
    ext_acl(std::string acl_file, std::string ip_file):
        acl_stmts(read_acl_file(acl_file)),
        comp_ips(read_ip_file(ip_file)){ }

    acl_stmts_t read_acl_file(std::string);
    std::vector<std::pair<ip, ip>> read_ip_file(std::string);
    void process();
    bool compare(std::pair<ip, ip>, std::pair<ip, ip>);
};
}

#endif