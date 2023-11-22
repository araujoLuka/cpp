#include <iostream>
#include <list>

int main() {
    std::list<int*> l{new int{3}, new int{1}, new int{2}, new int{5}};

    std::list<int*>::iterator it{l.begin()};
    for (; it != l.end(); ++it) {
        std::cout << **it << " ";
    }
}
