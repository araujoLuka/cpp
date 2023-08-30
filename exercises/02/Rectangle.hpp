/* Autor: Lucas Correira de Araujo
 * GRR: 20206150
 * Exercise 2 - Object-Oriented Programming C++
 * Headder with interface for Rectangle class
 */

/* Similar to include guard idiom
 * Prevents multiple inclusions of the contents of the headder file
 */
#pragma once
/*
 * Example in include guard idiom
 *      #ifndef RECTANGLE_HPP
 *      #define RECTANGLE_HPP
 */

// Codes placed here is included only once per translation unit (#pragma once
// effect)

class Rectangle {
   public:
    int calcArea(int length, int width);
    int calcPer(int length, int width);

    int calcScale(int length, int width);
    void draw(int length, int width, int scale);

    int length;
    int width;
    int drawScale;
};
