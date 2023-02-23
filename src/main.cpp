#include <bitset>
#include <iostream>
#include "std-acl.h"
#include "ip.h"
#include "ext-std-acl.h"

int main()
{
    std::cout << "================ STANDARD ACL ================"
              << "\n";
    std_acl::acl std_acl{"std-acl.txt", "std-ip.txt"};
    std_acl.process();
    std::cout << "================     END      ================"
              << "\n\n\n";

    std::cout << "================ EXTENDED ACL ================"
              << "\n";
    std_acl::ext_acl acl{"ext-acl.txt", "ext-ip.txt"};
    acl.process();
    std::cout << "================     END      ================"
              << "\n";
}