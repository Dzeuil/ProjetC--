#include "rationnel.hpp"

int main () {
    Rationnal x(3, 4);
    std::cout << x << '\n'; // affiche 3/4
    Rationnal y(1, 2);
    std::cout << y << '\n'; // affiche 1/2
    Rationnal z = x + y;
    std::cout << z << '\n';
    Rationnal a = z * x;
    std::cout << a << '\n';
    Rationnal b = x / y;
    std::cout << b << '\n';
    if (z == Rationnal(5, 8)) {
        std::cout << "Correct\n";
    } else {
        std::cout << "Incorrect\n";
    }
    if (a != Rationnal(11, 5)) {
        std::cout << "Correct\n";
    } else {
        std::cout << "Incorrect\n";
    }
    std::cout << (a < b) << '\n';
    std::cout << (y > z) << '\n';
    
    return 0;
}