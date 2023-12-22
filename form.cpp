#include"form.hpp"

int main () {
    Circle c(3,3,10);
    Rectangle r(3,3, 10,9);
    Triangle t(2,2,3,4,5);
    c.print();
    r.print();
    t.print();
    return 0;
}