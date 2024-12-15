#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Box {
private:
    double length, width, height;

public:
    Box(double l = 0, double w = 0, double h = 0) : length(l), width(w), height(h) {}

    // Overload the + operator
    Box operator+(const Box &b) {
        return Box(length + b.length, width + b.width, height + b.height);
    }

    // Overload the - operator
    Box operator-(const Box &b) {
        return Box(length - b.length, width - b.width, height - b.height);
    }

    // Overload the * operator
    Box operator*(double scalar) {
        return Box(length * scalar, width * scalar, height * scalar);
    }

    // Overload the / operator
    Box operator/(double scalar) {
        if (scalar == 0) {
            throw runtime_error("Division by zero is not allowed.");
        }
        return Box(length / scalar, width / scalar, height / scalar);
    }

    // Overload relational operators
    bool operator>(const Box &b) {
        return (length * width * height) > (b.length * b.width * b.height);
    }

    bool operator<=(const Box &b) {
        return (length * width * height) <= (b.length * b.width * b.height);
    }

    bool operator>=(const Box &b) {
        return (length * width * height) >= (b.length * b.width * b.height);
    }

    void display() const {
        cout << "Box dimensions: (" << length << ", " << width << ", " << height << ")" << endl;
    }

    static Box randomBox() {
        double l = rand() % 10 + 1;
        double w = rand() % 10 + 1; 
        double h = rand() % 10 + 1;
        return Box(l, w, h);
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    Box box1 = Box::randomBox();
    Box box2 = Box::randomBox();

    cout << "Randomly generated box1: ";
    box1.display();

    cout << "Randomly generated box2: ";
    box2.display();

    // Test + operator
    Box box3 = box1 + box2;
    cout << "box1 + box2 = ";
    box3.display();

    // Test - operator
    Box box4 = box1 - box2;
    cout << "box1 - box2 = ";
    box4.display();

    // Test * operator
    Box box5 = box1 * 2;
    cout << "box1 * 2 = ";
    box5.display();

    // Test / operator
    Box box6 = box1 / 2;
    cout << "box1 / 2 = ";
    box6.display();

    // Test relational operators
    cout << "box1 > box2: " << (box1 > box2 ? "true" : "false") << endl;
    cout << "box1 <= box2: " << (box1 <= box2 ? "true" : "false") << endl;
    cout << "box1 >= box2: " << (box1 >= box2 ? "true" : "false") << endl;

    return 0;
}

/*

Randomly generated box1: Box dimensions: (5, 7, 3)
Randomly generated box2: Box dimensions: (2, 4, 6)
box1 + box2 = Box dimensions: (7, 11, 9)
box1 - box2 = Box dimensions: (3, 3, -3)
box1 * 2 = Box dimensions: (10, 14, 6)
box1 / 2 = Box dimensions: (2.5, 3.5, 1.5)
box1 > box2: true
box1 <= box2: false
box1 >= box2: true



*/

