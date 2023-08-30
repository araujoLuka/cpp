/* Autor: Lucas Correira de Araujo
 * GRR: 20206150
 * Exercise 4 - Object-Oriented Programming C++
 * Implements member functions of Rectangle class
 */

#include "Rectangle.hpp"
#include <iomanip>
#include <iostream>

#define SCALE_STEP 35

Rectangle::Rectangle() 
    :length{10}, width(20) {
    calcScale();
}

Rectangle::Rectangle(uint32_t rLength, uint32_t rWidth) {
    setLength(rLength);
    setWidth(rWidth);
}

int Rectangle::getLength() {
    return length;
}

void Rectangle::setLength(int newLenght) {
    if (newLenght > 0) {
        length = newLenght;
        if (width != 0)
            calcScale();
        return;
    }
    length = 0;
}

int Rectangle::getWidth() {
    return width;
}

void Rectangle::setWidth(int newWidth) {
    if (newWidth > 0) {
        width = newWidth;
        if (length != 0)
            calcScale();
        return;
    }
    width = 0;
}

unsigned short int Rectangle::getScale() {
    return (unsigned short)scale;
}

int Rectangle::calcArea() {
    return length * width;
}

int Rectangle::calcPer() {
    return 2 * length + 2 * width;
}

int Rectangle::calcScale() {
    double prop {(double)length / width};
    int l{(int)length};
    int w{(int)width};
    int s;

    for (s = 1; l > SCALE_STEP || w > SCALE_STEP; s++) {
        l -= SCALE_STEP;
        w -= SCALE_STEP * prop;
    }

    scale = s;
    return s;
}

void Rectangle::draw() {
    uint32_t l = 2;
    uint32_t i;

    std::cout << "+ ";
    for (i = 2; i < length; i+=scale) {
        std::cout << "—— ";
        l+=3;
    }
    std::cout << "+" << '\n';

    for (i = 0; i < width; i+=scale) {
        std::cout << '|' << std::setw(l) << '|' << '\n';
    }

    std::cout << "+ ";
    for (i = 2; i < length; i+=scale) {
        std::cout << "—— ";
    }
    std::cout << "+" << '\n';
}
