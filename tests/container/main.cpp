#include <iostream>
#include <array>
#include <list>
#include <map>
#include <string>
#include <vector>

int main (int argc, char *argv[]) {
    // testing array container
    std::cout << "Testing array container...\n";
    std::array<int, 8> arr{1, 2, 3, 4, 5};
    std::cout << "arr: {1, 2, 3, 4, 5}" << '\n';
    std::cout << "arr.size(): " << arr.size() << '\n';
    std::cout << "arr.max_size(): " << arr.max_size() << '\n';
    std::cout << "arr[0]: " << arr[0] << '\n';
    std::cout << "arr.at(0): " << arr.at(0) << '\n';
    std::cout << "arr.front(): " << arr.front() << '\n';
    std::cout << "arr.back(): " << arr.back() << '\n';
    std::cout << "arr.data(): " << arr.data() << '\n';

    // testing vector container
    std::cout << "\nTesting vector container...\n";
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::cout << "vec: {1, 2, 3, 4, 5}\n";
    std::cout << "vec.size(): " << vec.size() << '\n';
    std::cout << "vec.max_size(): " << vec.max_size() << '\n';
    std::cout << "vec[0]: " << vec[0] << '\n';
    std::cout << "vec.at(0): " << vec.at(0) << '\n';
    std::cout << "vec.front(): " << vec.front() << '\n';
    std::cout << "vec.back(): " << vec.back() << '\n';
    std::cout << "vec.data(): " << vec.data() << '\n';
    vec.push_back(6);
    std::cout << "vec.push_back(6)\n";
    std::cout << "vec.size(): " << vec.size() << '\n';
    std::cout << "vec.max_size(): " << vec.max_size() << '\n';

    // testing list container
    std::cout << "\nTesting list container...\n";
    std::list<int> lst{1, 2, 3, 4, 5};
    std::cout << "lst: {1, 2, 3, 4, 5}\n";
    std::cout << "lst.size(): " << lst.size() << '\n';
    std::cout << "lst.max_size(): " << lst.max_size() << '\n';
    std::cout << "lst.front(): " << lst.front() << '\n';
    std::cout << "lst.back(): " << lst.back() << '\n';
    std::cout << "lst.push_back(6)\n";
    lst.push_back(6);
    std::cout << "lst.size(): " << lst.size() << '\n';
    std::cout << "lst.max_size(): " << lst.max_size() << '\n';

    // testing map container
    std::cout << "\nTesting map container...\n";
    std::map<int, std::string> mp{{1, "one"}, {2, "two"}, {3, "three"}};
    std::cout << "mp: {{1, \"one\"}, {2, \"two\"}, {3, \"three\"}}\n";
    std::cout << "mp.size(): " << mp.size() << '\n';
    std::cout << "mp.max_size(): " << mp.max_size() << '\n';
    for (auto it = mp.begin(); it != mp.end(); it++) {
        std::cout << "mp[" << it->first << "]: " << it->second << '\n';
    }
    mp[(--mp.end())->first + 1] = "four";
    std::cout << "mp[4] = \"four\"\n";
    std::cout << "mp[4]: " << mp[4] << '\n';
    mp.erase(2);
    std::cout << "mp.erase(2)\n";
    std::cout << "last element: " << mp[(--mp.end())->first] << '\n';
    mp.insert({(--mp.end())->first + 1, "five"});
    std::cout << "mp.insert({5, \"five\"})\n";
    std::cout << "mp[5]: " << mp[5] << '\n';
    std::cout << "mp.size(): " << mp.size() << '\n';
    std::cout << "mp.max_size(): " << mp.max_size() << '\n';
    for (std::map<int, std::string>::const_iterator it = mp.cbegin(); it != mp.cend(); it++) {
        std::cout << "mp[" << it->first << "]: " << it->second << '\n';
    }
    mp.insert({2, "two"});
    std::cout << "mp.insert({2, \"two\"})\n";
    std::cout << "mp[2]: " << mp[2] << '\n';
    std::cout << "mp.size(): " << mp.size() << '\n';
    for (std::map<int, std::string>::const_iterator it = mp.cbegin(); it != mp.cend(); it++) {
        std::cout << "mp[" << it->first << "]: " << it->second << '\n';
    }

    return 0;
}
