// stack.cpp
#include "stack.hpp"

int main() {
    Stack s(5);
    int * ti = new int[5];
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Size of Stack: " << s.size() << std::endl;

    s.pop();
    std::cout << "Size of Stack after popping an element: " << s.size() << std::endl;

    return 0;
}