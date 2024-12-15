#include <iostream>
#include <vector>
#include <algorithm> // std::unique

class EncapsulatedArray {
private:
    std::vector<int> array;

public:
    // Constructor
    EncapsulatedArray(const std::vector<int>& initialArray) : array(initialArray) {}

    // Swap two elements
    void swap(int index1, int index2) {
        if (index1 >= 0 && index1 < array.size() && index2 >= 0 && index2 < array.size()) {
            std::swap(array[index1], array[index2]);
        }
    }

    // Bubble sort
    void bubbleSort() {
        for (size_t i = 0; i < array.size() - 1; ++i) {
            for (size_t j = 0; j < array.size() - i - 1; ++j) {
                if (array[j] > array[j + 1]) {
                    swap(j, j + 1);
                }
            }
        }
    }

    // Selection sort
    void selectSort() {
        for (size_t i = 0; i < array.size() - 1; ++i) {
            size_t minIndex = i;
            for (size_t j = i + 1; j < array.size(); ++j) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            swap(i, minIndex);
        }
    }

    // Insertion sort
    void insertSort() {
        for (size_t i = 1; i < array.size(); ++i) {
            int temp = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > temp) {
                array[j + 1] = array[j];
                --j;
            }
            array[j + 1] = temp;
        }
    }

    // Delete an element by index
    void deleteIndex(int index_to_delete) {
        if (index_to_delete >= 0 && index_to_delete < array.size()) {
            array.erase(array.begin() + index_to_delete);
        }
    }

    // Remove duplicates from a sorted array
    void noDups() {
        auto end = std::unique(array.begin(), array.end());
        array.erase(end, array.end());
    }

    // Insert a number in order into a sorted array
    void insert_in_order(int number_to_insert) {
        auto position = std::lower_bound(array.begin(), array.end(), number_to_insert);
        array.insert(position, number_to_insert);
    }

    // Display the array
    void display() const {
        for (int num : array) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    EncapsulatedArray myArray({5, 3, 8, 6, 2, 7, 4, 1});

    std::cout << "Original array: ";
    myArray.display();

    std::cout << "After bubble sort: ";
    myArray.bubbleSort();
    myArray.display();

    myArray = EncapsulatedArray({5, 3, 8, 6, 2, 7, 4, 1});
    std::cout << "After selection sort: ";
    myArray.selectSort();
    myArray.display();

    myArray = EncapsulatedArray({5, 3, 8, 6, 2, 7, 4, 1});
    std::cout << "After insertion sort: ";
    myArray.insertSort();
    myArray.display();

    myArray.deleteIndex(3);
    std::cout << "After deleting index 3: ";
    myArray.display();

    myArray.noDups();
    std::cout << "After removing duplicates: ";
    myArray.display();

    myArray.insert_in_order(5);
    std::cout << "After inserting 5 in order: ";
    myArray.display();

    return 0;
}

/*

Original array: 5 3 8 6 2 7 4 1 
After bubble sort: 1 2 3 4 5 6 7 8 
After selection sort: 1 2 3 4 5 6 7 8 
After insertion sort: 1 2 3 4 5 6 7 8 
After deleting index 3: 1 2 3 5 6 7 8 
After removing duplicates: 1 2 3 5 6 7 8 
After inserting 5 in order: 1 2 3 5 5 6 7 8 


*/