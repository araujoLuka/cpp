/* Autor: Lucas Correira de Araujo
 * GRR: 20206150
 * Exercise 2 - Object-Oriented Programming C++
 * Implements member functions of Rectangle class
 */

#include "Rectangle.hpp"
#include <iomanip>
#include <iostream>

#define SCALE_STEP 80

int Rectangle::calcArea(int length, int width) {
    return length * width;
}

int Rectangle::calcPer(int length, int width) {
    return 2 * length + 2 * width;
}

int Rectangle::calcScale(int l, int w) {
    int s;
    double prop = (double)l / w;

    for (s = 1; l > SCALE_STEP || w > SCALE_STEP; s++) {
        l-=SCALE_STEP;
        w-=SCALE_STEP*prop;
    }

    return s;
}

void Rectangle::draw(int length, int width, int scale) {
    int l = 2;

    std::cout << "+ ";
    for (int i = 2; i < length; i+=scale) {
        std::cout << "— ";
        l+=2;
    }
    std::cout << "+" << '\n';

    for (int i = 0; i < width; i+=scale) {
        std::cout << '|' << std::setw(l)     << '|' << '\n';
    }

    std::cout << "+ ";
    for (int i = 2; i < length; i+=scale) {
        std::cout << "— ";
    }
    std::cout << "+" << '\n';
}
