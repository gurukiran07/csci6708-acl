#include <bitset>
#include <iostream>
#include "std-acl.h"
#include "ip.h"
#include "ext-std-acl.h"

int main(){
    std_acl::ext_acl acl{"acl.txt", "ip.txt"};
    acl.process();

}