#include "std-acl.h"

namespace std_acl{
acl::acl_stmts_t acl::read_acl_file(std::string filename){
    std::ifstream file{filename};
    std::string access_list, action, ip_addr, mask;
    int std_acl_num;
    acl_stmts_t stmts;
    while(file >> access_list >> std_acl_num >> action >> ip_addr){
        ip src;
        if (ip_addr != "any"){
            file >> mask;
            src = ip(ip_addr, mask);
        }
        else{
            src = ip("0.0.0.0", "255.255.255.255");
        }
        stmts.push_back({action, src});
    }
    file.close();
    return stmts;
}

std::vector<ip> acl::read_ip_file(std::string filename){
    std::ifstream file{filename};
    std::string ip_addr;
    std::vector<ip> comp;
    while(file >> ip_addr){
        comp.push_back(ip(ip_addr));
    }
    file.close();
    return comp;
}

void acl::process(){
    for(auto& comp_ip: comp_ips){
        bool deny_all = true;
        for(auto& acl_stmt: acl_stmts){
            if (acl_stmt.second == comp_ip){
                std::cout << "Packet from " << comp_ip.ip_repr << " " << (acl_stmt.first == "deny" ? pckt_denied: pckt_permitted) << "\n";
                deny_all = false;
                break;
            }
        }
        if (deny_all)
            std::cout << "Packet from " << comp_ip.ip_repr << " " << pckt_denied << "\n";
    }
}
}