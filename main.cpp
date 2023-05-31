#include <iostream>
#include <vector>
#include <forward_list>
#include <string>

template <typename T>
class unordered_map {
private:
    std::vector<std::forward_list<std::pair<std::string,T>>> vec_list;
    int hash_func(const std::string& key){
        int index = 0;
        for(int i = 0; i < key.size(); ++i) {
            index += static_cast<int>(key[i])/(i + 1);
        }
        std::cout << index/key.size() << std::endl;
        return index/key.size();
    }
public:
    unordered_map() {
        vec_list.resize(1000);
    }
    ~unordered_map(){

    }
    void insert(const std::string& key,T value) {
        const int index = hash_func(key);
        vec_list[index].push_front(std::make_pair(key,value));
    }
    void remove(const std::string& key) {
        const int index = hash_func(key);
        auto& bucket = vec_list[index];
        for (auto it = bucket.begin(), before_it = bucket.before_begin() ; it != bucket.end(); ++it,++before_it) {
            if (it->first == key) {
                bucket.erase_after(before_it);
                return;
            }
        }
    }
    T& operator[](const std::string& key) {
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
    const std::pair<std::string,T>* find(const std::string& key) {
        const int index = hash_func(key);
        auto& bucket = vec_list[index];
        for (const auto& pair : bucket) {
            if (pair.first == key) {
                return &pair;
            }
        }
        std::cout<<"not found";
        return nullptr;

    }
};
int main() {
    unordered_map<int> map;
    map.insert("one", 1);
    map.insert("two", 2);
    map.insert("three", 3);

    std::cout << "Value of 'one': " << map["one"] << std::endl;
    std::cout << "Value of 'two': " << map["two"] << std::endl;
    std::cout << "Value of 'three': " << map["three"] << std::endl;

    map["four"] = 4;
    std::cout << "Value of 'four': " << map["four"] << std::endl;
    map.remove("four");
    auto it = map.find("four");

    if(it != nullptr)
    std::cout<< it->second ;

    return 0;
}
