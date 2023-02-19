#include <iostream>
#include "std-acl.h"
#include "ip.h"
#include <bitset>

int main(){
    std::string filename = "ip.txt";
    //std_acl::read_file(filename);
    std_acl::ip ip_data("172.16.50.32", "0.0.0.7");
    std::cout << (ip_data == "172.16.50.31") << "\n";
}