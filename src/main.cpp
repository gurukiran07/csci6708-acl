#include <iostream>
#include "std-acl.h"
#include "ip.h"

int main(){
    std::string filename = "ip.txt";
    std_acl::read_file(filename);
    std_acl::ip ip_data("172.16.0.0", "0.0.255.255");
    std::cout << (ip_data == "172.16.0.0");
}