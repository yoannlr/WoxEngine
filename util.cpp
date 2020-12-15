#include <iostream>
#include <map>
#include <vector>

template<typename K, typename V>
void printMap(std::map<K, V> const &m) {
	for (auto it = m.cbegin(); it != m.cend(); ++it) {
        std::cout << "{" << it->first << ": " << it->second << "}\n";
    }
}

template<typename T>
void printVector(std::vector<T> const &v) {
    for (auto it = v.cbegin(); it != v.cend(); it++) {
        std::cout << *it << ' ';
    }
	std::cout << "\n";
}