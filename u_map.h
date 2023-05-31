

#ifndef U_MAP_H
#define U_MAP_H
#include <iostream>
#include <vector>
#include <forward_list>
#include <string>
template <typename T>
class unordered_map {
private:
    std::vector<std::forward_list<std::pair<std::string,T>>> vec_list;
    int hash_func(const std::string& key);
public:
    unordered_map() ;
    ~unordered_map();
    void insert(const std::string& key,T value);
    void remove(const std::string& key);
    T& operator[](const std::string& key);
    const std::pair<std::string,T>* find(const std::string& key);
};
#include "u_map.hpp"

#endif 