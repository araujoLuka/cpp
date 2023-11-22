#include <iostream>

#include "ClasseA.hpp"

int main() {
    ClasseA ca;
    int* par{new int{40}};
    const int* ret{ca.minhaFunc(par)};

    std::cout << *ret << ' ' << *par << std::endl;

    delete ret;
    delete par;

    return 0;
}
