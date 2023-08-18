/* Autor: Lucas Correira de Araujo
 * GRR: 20206150
 *
 * Exercise 2 - Object-Oriented Programming C++
 * Main program to use Rectangle Class
 *
 * Description:
 *      Get data from two rectangles and calculate their area and perimeter.
 *      Also calculate the difference between the area of the rectangles.
 */

#include <cstdlib>
#include <iostream>

#include "Rectangle.hpp"


int main() {
    Rectangle r1, r2;

    std::cout << "Enter lenght and width of the first rectangle: ";
    std::cin >> r1.length >> r1.width;
    r1.drawScale = r1.calcScale(r1.length, r1.width);

    std::cout << "Enter lenght and width of the second rectangle: ";
    std::cin >> r2.length >> r2.width;
    r2.drawScale = r2.calcScale(r2.length, r2.width);

    std::cout << "\n---\n";
    std::cout << "Rectangle #1\n";
    std::cout << "- Lenght: " << r1.length << "\n";
    std::cout << "- Width: " << r1.width << "\n";
    std::cout << "- Area: " << r1.calcArea(r1.length, r1.width) << "\n";
    std::cout << "- Perimeter: " << r1.calcPer(r1.length, r1.width) << "\n";
    std::cout << "- Draw (Scale = " << r1.drawScale << "x): \n";
    r1.draw(r1.length, r1.width, r1.drawScale);

    std::cout << "\n---\n";
    std::cout << "Rectangle #2\n";
    std::cout << "- Lenght: " << r2.length << "\n";
    std::cout << "- Width: " << r2.width << "\n";
    std::cout << "- Area: " << r2.calcArea(r2.length, r2.width) << "\n";
    std::cout << "- Perimeter: " << r2.calcPer(r2.length, r2.width) << "\n";
    std::cout << "- Draw (Scale = " << r2.drawScale << "x): \n";
    r2.draw(r2.length, r2.width, r2.drawScale);

    std::cout << "\n---\n";
    std::cout << "Difference of the areas: " << 
        abs(r1.calcArea(r1.length, r1.width) - r2.calcArea(r2.length, r2.width)) << "\n";

    return 0;
}
