#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>

namespace std_acl{
    std::string acl = "stdandard ACL";

    class acl{
        std::unordered_set<std::string> permit;
        std::unordered_set<std::string> deny;
        std::string flag;

    };
    
    void read_file(std::string filename){
        std::ifstream file{filename};
        std::string line;

        while(std::getline(file, line)){
            std::cout << line << "\n";
        }

    }
};