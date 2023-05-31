#include "u_map.h"
template<typename T>
int unordered_map<T>::hash_func(const std::string& key){
    int index = 0;
    for(int i = 0; i < key.size(); ++i) {
        index += static_cast<int>(key[i])/(i + 1);
    }
    return index/key.size();
}
template<typename T>
unordered_map<T>::unordered_map() {
    vec_list.resize(1000);
}
template<typename T>
unordered_map<T>::~unordered_map(){

}
template<typename T>
void unordered_map<T>::insert(const std::string& key,T value) {
    const int index = hash_func(key);
    auto& bucket = vec_list[index];
    for (auto it = bucket.begin(), before_it = bucket.before_begin() ; it != bucket.end(); ++it,++before_it) {
        if (it->first == key) {
            return;
        }
    }
    vec_list[index].push_front(std::make_pair(key,value));
}
template<typename T>
void unordered_map<T>::remove(const std::string& key) {
    const int index = hash_func(key);
    auto& bucket = vec_list[index];
    for (auto it = bucket.begin(), before_it = bucket.before_begin() ; it != bucket.end(); ++it,++before_it) {
        if (it->first == key) {
            bucket.erase_after(before_it);
            return;
        }
    }
}
template<typename T>
T& unordered_map<T>::operator[](const std::string& key) {
    const int index = hash_func(key);
    auto& bucket = vec_list[index];

    for (auto& pair : bucket) {
        if (pair.first == key) {
            return pair.second;
        }
    }

    bucket.push_front(std::make_pair(key, T{}));
    return bucket.front().second;
}
template<typename T>
const std::pair<std::string,T>* unordered_map<T>::find(const std::string& key) {
    const int index = hash_func(key);
    auto& bucket = vec_list[index];
    for (const auto& pair : bucket) {
        if (pair.first == key) {
            return &pair;
        }
    }
    std::cout<<"not found"<<std::endl;
    return nullptr;

}