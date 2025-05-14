#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const double PI = 3.14159265358979323846;


class Figure {
protected:
    double length;
    double width;

public:
    Figure() : length(0), width(0) {}
    Figure(double l, double w) : length(l), width(w) {}

    double getLength() const { return length; }
    double getWidth() const { return width; }

    virtual double area() const {
        return length * width;
    }

    virtual double perimeter() const {
        return 2 * (length + width);
    }

    virtual ~Figure() {}
};

class Ellipse : public Figure {
public:
    Ellipse() : Figure() {}
    Ellipse(double a, double b) : Figure(a, b) {}

    double area() const override {
        return PI * length * width;
    }

    double perimeter() const override {
        return PI * (3 * (length + width) - sqrt((3 * length + width) * (length + 3 * width)));
    }
};

class Circle : public Figure {
public:
    Circle() : Figure() {}
    Circle(double r) : Figure(r, r) {}

    double area() const override {
        return PI * length * length;
    }

    double perimeter() const override {
        return 2 * PI * length;
    }
};

void displayFigureInfo(const Figure& fig) {
    cout << "Area: " << fig.area() << endl;
    cout << "Perimeter: " << fig.perimeter() << endl;
}

int main() {
    Ellipse e(3.0, 2.0);
    Circle c(5.0);

    cout << "--- Ellipse ---" << endl;
    displayFigureInfo(e);

    cout << "--- Circle ---" << endl;
    displayFigureInfo(c);

    return 0;
}
