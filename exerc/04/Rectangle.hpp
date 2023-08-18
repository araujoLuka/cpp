/* Autor: Lucas Correira de Araujo
 * GRR: 20206150
 * Exercise 4 - Object-Oriented Programming C++
 * Headder with interface for Rectangle class
 */

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <cstdint>

class Rectangle {
   public:
    Rectangle();
    Rectangle(uint32_t rLength, uint32_t rWidth = 15);

    int getLength();
    void setLength(int newLenght);

    int getWidth();
    void setWidth(int newWidth);

    unsigned short int getScale();

    int calcArea();
    int calcPer();

    void draw();

   private:
    int calcScale();

    uint32_t length;
    uint32_t width;
    uint8_t scale;
};

#endif
