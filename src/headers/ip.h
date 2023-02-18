#include <string>
#include <utility>
#include <array>
#include <sstream>
#include <string>

namespace std_acl{

class ip{
    std::array<std::pair<int, bool>, 4> ip_data{};
    
    public:
    ip(std::string ip_addr, std::string mask = "0.0.0.0"): ip_data(split(ip_addr, mask)){
        
    }
    std::array<std::pair<int, bool>, 4> split(std::string ip_addr, std::string mask = "0.0.0.0");
    bool operator==(std::string ip_addr);
};

}