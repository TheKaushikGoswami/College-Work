#include <iostream>
using namespace std;

// A simple Point class
class Point {
private:
    int x, y;  // Coordinates of the point

public:
    // Constructor
    Point(int xValue = 0, int yValue = 0) : x(xValue), y(yValue) {}

    // Overload the '+' operator
    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);  // Add corresponding x and y
    }

    // Display the point
    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p1(3, 4);  // First point
    Point p2(1, 2);  // Second point

    Point p3 = p1 + p2;  // Use overloaded '+' operator

    cout << "Point 1: ";
    p1.display();  // Output: (3, 4)

    cout << "Point 2: ";
    p2.display();  // Output: (1, 2)

    cout << "Result of addition: ";
    p3.display();  // Output: (4, 6)

    return 0;
}
