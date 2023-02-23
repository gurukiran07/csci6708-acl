#include <iostream>
#include "ext-std-acl.h"


namespace std_acl{
    ext_acl::acl_stmts_t ext_acl::read_acl_file(std::string filename){
        std::ifstream file{filename};
        std::string access_list, action, protocol, src_ip, src_mask, dst_ip, dst_mask, op, port_range;
        size_t ext_acl_num;
        acl_stmts_t stmts;

        while(file >> access_list >> ext_acl_num >> action >> protocol ){
            ip src, dst;
            file >> src_ip;
            if (src_ip == "any"){
                src = ip("0.0.0.0", "255.255.255.255");
                file >> dst_ip;
                if (dst_ip != "any"){
                    file >> dst_mask;
                    dst = ip(dst_ip, dst_mask);
                }
                else{
                    dst = ip("0.0.0.0", "255.255.255.255");
                }
            }
            else{
                file >> src_mask >> dst_ip;
                src = ip(src_ip, src_mask);
                if (dst_ip != "any"){
                    file >> dst_mask;
                    dst = ip(dst_ip, dst_mask);
                }
                else{
                    dst = ip("0.0.0.0", "255.255.255.255");
                }
            }

            if (protocol != "ip"){
                file >> op >> port_range;
                src.set_ports(port_range);
                dst.set_ports(port_range);
            }
            stmts.push_back({
                action,
                {src, dst}
            });
        }
        return stmts;
    }
   

    std::vector<std::pair<ip, ip>> ext_acl::read_ip_file(std::string filename){
        std::ifstream file{filename};
        std::vector<std::pair<ip, ip>> comp;
        std::string src_ip, dst_ip, port;
        while(file >> src_ip >> dst_ip >> port){
            ip src = ip(src_ip);
            ip dst = ip(dst_ip);
            src.set_ports(port);
            dst.set_ports(port);
            comp.push_back(
                {src, dst}
            );
        }
        return comp;
    };

    bool ext_acl::compare(std::pair<ip, ip> src, std::pair<ip, ip> dst){
        bool flag = true;
        auto src_ip = src.first;
        auto dst_ip = src.second;
        flag &= (src_ip == dst.first);
        flag &= (dst_ip == dst.second);  
        return flag;
    }
    void ext_acl::process(){
        for(auto& comp_ip: comp_ips){
            bool deny_all = true;
            for(auto& acl_stmt: acl_stmts){
                if (compare(acl_stmt.second, comp_ip)){
                    std::cout << "Packet from " << comp_ip.first.ip_repr 
                        << " to " << comp_ip.second.ip_repr 
                        << " on port " << *(comp_ip.first.get_ports().begin()) << " "
                        << (acl_stmt.first == "deny" ? pckt_denied : pckt_permitted)
                        << "\n";
                    deny_all = false;
                    break;
                }
            }
            if (deny_all){
                std::cout << "D Packet from " << comp_ip.first.ip_repr 
                    << " to " << comp_ip.second.ip_repr 
                    << " on port " << *(comp_ip.first.get_ports().begin()) << " "
                    << pckt_denied << "\n";
            }
        }
    }
}