/* Autor: Lucas Correira de Araujo
 * GRR: 20206150
 *
 * Exercise 4 - Object-Oriented Programming C++
 * Main program to use Rectangle Class
 *
 * Description:
 *      Get data from two rectangles and calculate their area and perimeter.
 *      Also calculate the difference between the area of the rectangles.
 */

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>

#include "Rectangle.hpp"


int main() {
    uint32_t length, width;
    Rectangle r1;

    std::cout << "Default rectangle created: \n";
    std::cout << "Length: " << r1.getLength() << " - "
              << "Width: "  << r1.getWidth()  << "\n";

    std::cout << "Enter lenght and width to change this rectangle: ";
    std::cin >> length >> width;
    r1.setLength(length);
    r1.setWidth(width);

    std::cout << "Enter lenght and width of the second rectangle: ";
    std::cin >> length >> width;
    std::cout << "\nATTENTION: I don't like this width and gonna use the default width! :)\n";
    Rectangle r2{length};

    std::cout << "___\n\n";
    std::cout << "Rectangle #1\n";
    std::cout << "- Lenght: " << r1.getLength() << "\n";
    std::cout << "- Width: " << r1.getWidth() << "\n";
    std::cout << "- Area: " << r1.calcArea() << "\n";
    std::cout << "- Perimeter: " << r1.calcPer() << "\n";
    std::cout << "- Draw (Scale = " << r1.getScale() << "x): \n";
    r1.draw();

    std::cout << "___\n\n";
    std::cout << "Rectangle #2\n";
    std::cout << "- Lenght: " << r2.getLength() << "\n";
    std::cout << "- Width: " << r2.getWidth() << "\n";
    std::cout << "- Area: " << r2.calcArea() << "\n";
    std::cout << "- Perimeter: " << r2.calcPer() << "\n";
    std::cout << "- Draw (Scale = " << r2.getScale() << "x): \n";
    r2.draw();

    std::cout << "___\n\n";
    std::cout << "Difference of the areas: " << 
        abs(r1.calcArea() - r2.calcArea()) << "\n";

    return 0;
}
