#include <iostream>
#include "u_map.h"
int main() {
    unordered_map<int> map;
    map.insert("Saqo", 1);
    map.insert("Armen", 2);
    map.insert("Harut", 3);
    map.insert("Mish", 4);
    std::cout << map["Saqo"] << std::endl;
    std::cout << map["Armen"] << std::endl;
    std::cout << map["Harut"] << std::endl;
    std::cout << map["Mish"] << std::endl;
    map["Gev"] = 5;
    std::cout << map["Gev"] << std::endl;
    map.remove("Gev");
    auto it = map.find("Mish");
    auto it1 = map.find("Gev");
    auto it2 = map.find("Xevond");
    if(it != nullptr)
    std::cout<< it->second ;
    if(it1 != nullptr)
    std::cout<< it->second ;
    if(it2 != nullptr)
    std::cout<< it->second ;

    return 0;
}