#include <iostream>
#include "project/map.h"

int main() {
    Map map;

    map.insert("apple", 10);
    map.insert("banana", 20);
    map.insert("orange", 30);

    std::cout << "Lab 11 - Map Data Structure\n";
    std::cout << "Map size: " << map.size() << "\n";
    std::cout << "Apple value: " << map.at("apple") << "\n";

    return 0;
}