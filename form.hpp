#include <iostream>
#include <math.h>

using namespace std;

class Shape {
    protected:
        int x, y, area;
    public:
        Shape(int x, int y) : x(x), y(y) {}

        Shape(int x, int y, int area) : x(x), y(y), area(area) {};

        void move(int x, int y) {
            this->x += x;
            this->y += y;
        }
};

class Circle : public Shape {
    private:
        int radius;
        int area;
    public:
        Circle(int x, int y, int radius) : Shape(x,y), radius(radius) {}

        void print () {
            area = 3,14 * radius^(2);
            cout << "Circle at (" << x << "," << y << ") with radius " << radius << " and an area of " << area << endl;
        }
};

class Rectangle : public Shape {
    private:
        int width, height, area;
    public:
        Rectangle(int x, int y, int width, int height) : Shape (x, y), width(width), height(height) {}

        void print () {
            area = width * height;
            cout << "Rectangle at (" << x << "," << y << ") with width " << width << " and an area of " << area << endl;
        }
};

class Triangle : public Shape {
    private:
        int cote1, cote2, cote3;
        double perimetre;
        double p2;
        double area;

    public:
        Triangle (int x, int y, int a, int b, int c) : Shape(x,y), cote1(a), cote2(b), cote3(c) {
            perimetre = cote1+cote2+cote3;
            p2 = (cote1+cote2+cote3)/2;
            int aire = p2 * (p2 - cote1) * (p2 - cote2) * (p2 - cote3);
            area = sqrt(aire);
        }
        void print() {
            cout << "Triangle at (" << x << "," << y << ") with a perimetre of " << perimetre << " and an area of " << area << endl;
        };
};