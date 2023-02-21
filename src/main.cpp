#include <iostream>
#include "std-acl.h"
#include "ip.h"
#include <bitset>

int main(){
    std_acl::acl acl_start{"acl.txt", "ip.txt"};
    acl_start.process();
}