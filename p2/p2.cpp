#include <iostream>
using namespace std;

class Person {
private:
    // Private properties
    int age;
    float weight; // Added weight as a private property

public:
    // Public actions for age
    void showAge();
    void changeAge(int newAge);
    
    // Public actions for weight
    void showWeight();          // Show weight
    void changeWeight(float newWeight); // Change weight

    // Constructors
    Person();              // Default constructor
    Person(int newAge, float newWeight); // Parameterized constructor
};

// Definitions for age actions
void Person::showAge() {
    cout << "Age: " << age << endl;
}

void Person::changeAge(int newAge) {
    age = newAge;
}

// Definitions for weight actions
void Person::showWeight() {
    cout << "Weight: " << weight << " kg" << endl;
}

void Person::changeWeight(float newWeight) {
    weight = newWeight;
}

// Constructor definitions
Person::Person() {
    age = 19;       // Default age
    weight = 110.0;   // Default weight
}

Person::Person(int newAge, float newWeight) {
    age = newAge;
    weight = newWeight;
}

int main() {
    // Using the default constructor
    Person alex;
    alex.showAge();
    alex.showWeight();
    alex.changeAge(36);
    alex.changeWeight(75.5);
    alex.showAge();
    alex.showWeight();

    // Using the parameterized constructor
    Person child(8, 30.2);
    child.showAge();
    child.showWeight();

    return 0;
}


/*
Age: 101
Weight: 70 kg
Age: 36
Weight: 75.5 kg
Age: 8
Weight: 30.2 kg

*/