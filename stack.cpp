// stack.cpp
#include "stack.hpp"

int main() {
    Stack <char,int> s(5);
    s.push('u');
    s.push('v');
    s.push('w');

    std::cout << "Size of Stack: " << s.size() << std::endl;

    s.pop();
    //std::cout << "Size of Stack after popping an element: " << s.size() << std::endl;

    return 0;
}