#include <iostream>
#include <cstdlib> // For random number generation
#include <ctime>   // For seeding random number generator
using namespace std;

class EncapsulatedArray {
private:
    int *array; // Dynamically allocated array
    int number_of_elements;
    int capacity; // Total capacity of the array

public:
    EncapsulatedArray(int size);
    ~EncapsulatedArray();
    void add(int number_to_add);
    void show();
    void insertFirst(int number_to_add);
    void deleteNumber(int number_to_delete);
    void sort();
    void addRandomNumbers(int count, int min, int max); // Add random numbers to the array
};

// Constructor
EncapsulatedArray::EncapsulatedArray(int size) {
    array = new int[size];
    capacity = size;
    number_of_elements = 0;
}

// Destructor
EncapsulatedArray::~EncapsulatedArray() {
    delete[] array;
}

// Add an element to the end
void EncapsulatedArray::add(int number_to_add) {
    if (number_of_elements < capacity) {
        array[number_of_elements] = number_to_add;
        number_of_elements++;
    } else {
        cout << "Array is full, cannot add more elements." << endl;
    }
}

// Display the array
void EncapsulatedArray::show() {
    if (number_of_elements == 0) {
        cout << "array = {}\n";
        return;
    }

    cout << "array = {";
    for (int i = 0; i < number_of_elements - 1; i++) {
        cout << array[i] << ", ";
    }
    cout << array[number_of_elements - 1] << "}\n";
}

// Insert at the beginning and shift elements to the right
void EncapsulatedArray::insertFirst(int number_to_add) {
    if (number_of_elements < capacity) {
        for (int i = number_of_elements; i > 0; i--) {
            array[i] = array[i - 1];
        }
        array[0] = number_to_add;
        number_of_elements++;
    } else {
        cout << "Array is full, cannot insert." << endl;
    }
}

// Delete a specific number and shift elements to the left
void EncapsulatedArray::deleteNumber(int number_to_delete) {
    int index = -1;
    for (int i = 0; i < number_of_elements; i++) {
        if (array[i] == number_to_delete) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < number_of_elements - 1; i++) {
            array[i] = array[i + 1];
        }
        number_of_elements--;
        cout << "Deleted number " << number_to_delete << " from the array." << endl;
    } else {
        cout << "Number " << number_to_delete << " not found in the array." << endl;
    }
}

// Bubble sort
void EncapsulatedArray::sort() {
    for (int i = 0; i < number_of_elements - 1; i++) {
        for (int j = 0; j < number_of_elements - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Add random numbers to the array
void EncapsulatedArray::addRandomNumbers(int count, int min, int max) {
    for (int i = 0; i < count && number_of_elements < capacity; i++) {
        int random_number = rand() % (max - min + 1) + min;
        add(random_number);
    }
}

// Main function
int main() {
    srand(time(0)); // Seed the random number generator

    EncapsulatedArray anArray(10);

    // Test add()
    anArray.add(9);
    anArray.add(101);
    anArray.add(9);
    anArray.show();

    // Test insertFirst()
    anArray.insertFirst(42);
    anArray.show();

    // Test deleteNumber()
    anArray.deleteNumber(9);
    anArray.show();

    anArray.deleteNumber(101);
    anArray.show();

    // Test sort()
    anArray.add(15);
    anArray.add(7);
    anArray.sort();
    anArray.show();

    // Test addRandomNumbers()
    anArray.addRandomNumbers(5, 1, 100); // Add 5 random numbers between 1 and 100
    anArray.show();

    // Repeat all tests with a new random array
    EncapsulatedArray anotherArray(10);
    anotherArray.addRandomNumbers(5, 1, 100); // Add 5 random numbers between 1 and 100
    anotherArray.show();

    anotherArray.insertFirst(50);
    anotherArray.show();

    anotherArray.deleteNumber(50);
    anotherArray.show();

    anotherArray.sort();
    anotherArray.show();

    anotherArray.addRandomNumbers(3, 10, 50); // Add 3 random numbers between 10 and 50
    anotherArray.show();

    return 0;
}


/*
array = {9, 101, 9}
array = {42, 9, 101, 9}
Deleted number 9 from the array.
array = {42, 101, 9}
Deleted number 101 from the array.
array = {42, 9}
array = {7, 9, 15, 42}

array = {7, 9, 15, 42, 5, 72, 19, 81, 68}
array = {48, 85, 65, 45, 84}
array = {50, 48, 85, 65, 45, 84}
Deleted number 50 from the array.
array = {48, 85, 65, 45, 84}
array = {45, 48, 65, 84, 85}
array = {45, 48, 65, 84, 85, 38, 21, 14}
*/
