#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
using namespace std;

// Link class represents a single node in the linked list
class Link {
public:
    int iData;
    Link* next;

    Link(int data) : iData(data), next(nullptr) {}
};

// LinkList class represents the linked list
class LinkList {
private:
    Link* head;

public:
    LinkList() : head(nullptr) {}

    ~LinkList() {
        while (head != nullptr) {
            Link* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert at the beginning of the list
    void insertFirst(int data) {
        Link* newLink = new Link(data);
        newLink->next = head;
        head = newLink;
    }

    // Insert in order
    void insertInOrder(int data) {
        Link* newLink = new Link(data);
        if (!head || head->iData >= data) {
            newLink->next = head;
            head = newLink;
            return;
        }
        Link* current = head;
        while (current->next && current->next->iData < data) {
            current = current->next;
        }
        newLink->next = current->next;
        current->next = newLink;
    }

    // Delete the first node
    void deleteFirst() {
        if (!head) return;
        Link* temp = head;
        head = head->next;
        delete temp;
    }

    // Display the list
    void show() {
        Link* current = head;
        while (current) {
            cout << current->iData << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Sum of all iData
    int sumData() {
        int sum = 0;
        Link* current = head;
        while (current) {
            sum += current->iData;
            current = current->next;
        }
        return sum;
    }

    // Minimum iData
    int min() {
        if (!head) return numeric_limits<int>::max();
        int minVal = head->iData;
        Link* current = head->next;
        while (current) {
            if (current->iData < minVal) {
                minVal = current->iData;
            }
            current = current->next;
        }
        return minVal;
    }

    // Total number of links
    int numLinks() {
        int count = 0;
        Link* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main() {
    srand(time(0)); // Seed for random number generation

    LinkList list;

    // Part 2: Test the linked list
    list.insertFirst(10);
    list.insertFirst(20);
    list.insertFirst(30);
    list.insertInOrder(15);
    list.insertInOrder(5);
    list.show();

    // Test with random numbers
    cout << "Adding random numbers to the list..." << endl;
    for (int i = 0; i < 5; i++) {
        int randomNumber = rand() % 100; // Random number between 0 and 99
        list.insertInOrder(randomNumber);
    }
    list.show();

    // Part 5: Test new methods
    cout << "Sum of all data: " << list.sumData() << endl;
    cout << "Minimum value: " << list.min() << endl;
    cout << "Total number of links: " << list.numLinks() << endl;

    // Delete first node and show results
    list.deleteFirst();
    list.show();

    return 0;
}

/*
@NottKoneko ➜ /workspaces/cppclass2/p7 (main) $ ./p7
5 -> 15 -> 30 -> 20 -> 10 -> NULL
Adding random numbers to the list...
5 -> 15 -> 18 -> 30 -> 20 -> 10 -> 42 -> 71 -> 75 -> 91 -> NULL
Sum of all data: 377
Minimum value: 5
Total number of links: 10
15 -> 18 -> 30 -> 20 -> 10 -> 42 -> 71 -> 75 -> 91 -> NULL
*/
