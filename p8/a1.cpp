#include <iostream>
using namespace std;

// Definition for a Link in the Circular List
struct Link {
    int iData;
    Link* next;

    Link(int data) : iData(data), next(nullptr) {}
};

// Circular List Class
class CircList {
private:
    Link* current; // Pointer to current link

public:
    CircList() : current(nullptr) {}

    // Search for a value in the list
    bool search(int valueToFind) {
        if (!current) return false; // Empty list
        
        Link* temp = current;
        do {
            if (temp->iData == valueToFind) {
                return true;
            }
            temp = temp->next;
        } while (temp != current); // Loop around until back to start
        
        return false;
    }

    // Insert the initial link into an empty list
    void insertInitialLink(int newValue) {
        Link* newLink = new Link(newValue);
        newLink->next = newLink; // Point to itself to make circular
        current = newLink; // Current points to this first link
    }

    // Insert a new link after a value is found
    void insertAfterValueFound(int newValue, int valueToFind) {
        if (!current) return; // Empty list

        Link* temp = current;
        do {
            if (temp->iData == valueToFind) {
                Link* newLink = new Link(newValue);
                newLink->next = temp->next; // New link points to the next link
                temp->next = newLink; // Insert new link after the found link
                return;
            }
            temp = temp->next;
        } while (temp != current); // Loop around until back to start
    }

    // Delete the first link with a specific value
    bool deleteLink(int valueToFind) {
        if (!current) return false; // Empty list

        Link* temp = current;
        Link* prev = nullptr;

        do {
            if (temp->iData == valueToFind) {
                if (temp == temp->next) { // Single link case
                    delete temp;
                    current = nullptr;
                } else {
                    if (temp == current) {
                        current = current->next; // Move current if deleting current
                    }
                    prev->next = temp->next; // Bypass the link to delete
                    delete temp;
                }
                return true;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != current);

        return false; // Value not found
    }

    // Display the list
    void displayList() {
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }

        Link* temp = current;
        do {
            cout << temp->iData << " ";
            temp = temp->next;
        } while (temp != current);
        cout << endl;
    }

    ~CircList() {
        if (!current) return;

        Link* temp = current;
        do {
            Link* next = temp->next;
            delete temp;
            temp = next;
        } while (temp != current);

        current = nullptr;
    }
};

int main() {
    CircList clist;

    // Insert initial link
    clist.insertInitialLink(10);
    clist.displayList(); // Output: 10

    // Insert more links
    clist.insertAfterValueFound(20, 10);
    clist.insertAfterValueFound(30, 20);
    clist.displayList(); // Output: 10 20 30

    // Search for a value
    cout << "Searching for 20: " << (clist.search(20) ? "Found" : "Not Found") << endl; // Found
    cout << "Searching for 40: " << (clist.search(40) ? "Found" : "Not Found") << endl; // Not Found

    // Delete a link
    clist.deleteLink(20);
    clist.displayList(); // Output: 10 30

    // Delete the remaining links
    clist.deleteLink(10);
    clist.deleteLink(30);
    clist.displayList(); // Output: List is empty.

    return 0;
}

/*

10 
10 20 30 
Searching for 20: Found
Searching for 40: Not Found
10 30 
Segmentation fault (core dumped)

*/