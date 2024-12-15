#include <iostream>
#include <iomanip> 
using namespace std;

class Link {
public:
    int data;       
    Link* pNext, *pPrev; 

    Link(int newData) {
        data = newData;
        pNext = nullptr;
        pPrev = nullptr;
    }

    void display() {
        cout << "{ " << setw(14) << pPrev << "\t:\t" 
             << setw(3) << data << "\t:\t" 
             << setw(14) << pNext << " }" << endl;
    }
};

class DoubleEndedList {
private:
    Link* pFirst; 
    Link* pLast; 

public:
    DoubleEndedList() : pFirst(nullptr), pLast(nullptr) {}

    // Display the list from front to end
    void displayList() {
        cout << "List Forward:\n";
        Link* current = pFirst;
        while (current != nullptr) {
            current->display();
            current = current->pNext;
        }
    }

    // Display the list from end to front
    void displayBackward() {
        cout << "List Backward:\n";
        Link* current = pLast;
        while (current != nullptr) {
            current->display();
            current = current->pPrev;
        }
    }

    // Insert in ascending order
    void insert(int newValue) {
        Link* newLink = new Link(newValue);
        if (pFirst == nullptr) { 
            pFirst = pLast = newLink;
        } else if (newValue <= pFirst->data) { 
            newLink->pNext = pFirst;
            pFirst->pPrev = newLink;
            pFirst = newLink;
        } else if (newValue >= pLast->data) { 
            newLink->pPrev = pLast;
            pLast->pNext = newLink;
            pLast = newLink;
        } else {
            Link* current = pFirst;
            while (current != nullptr && current->data < newValue) {
                current = current->pNext;
            }
            newLink->pNext = current;
            newLink->pPrev = current->pPrev;
            current->pPrev->pNext = newLink;
            current->pPrev = newLink;
        }
    }

    // Remove the first link
    void removeFirst() {
        if (!pFirst) return;
        Link* temp = pFirst;
        pFirst = pFirst->pNext;
        if (pFirst) pFirst->pPrev = nullptr;
        else pLast = nullptr; 
        delete temp;
    }

    // Remove the last link
    void removeLast() {
        if (!pLast) return;
        Link* temp = pLast;
        pLast = pLast->pPrev;
        if (pLast) pLast->pNext = nullptr;
        else pFirst = nullptr;
        delete temp;
    }

    // Remove a link with a specific value
    void removeValue(int value) {
        Link* current = pFirst;
        while (current && current->data != value) {
            current = current->pNext;
        }
        if (!current) return;

        if (current == pFirst) removeFirst();
        else if (current == pLast) removeLast();
        else {
            current->pPrev->pNext = current->pNext;
            current->pNext->pPrev = current->pPrev;
            delete current;
        }
    }

    // Destructor to clean up memory
    ~DoubleEndedList() {
        while (pFirst) {
            removeFirst();
        }
    }
};

int main() {
    DoubleEndedList list;

    cout << "Inserting: 5, 3, 10, 7, 1, 6\n";
    list.insert(5);
    list.insert(3);
    list.insert(10);
    list.insert(7);
    list.insert(1);
    list.insert(6);

    list.displayList();
    list.displayBackward();

    cout << "\nRemoving first element...\n";
    list.removeFirst();
    list.displayList();

    cout << "\nRemoving last element...\n";
    list.removeLast();
    list.displayList();

    cout << "\nRemoving value 7...\n";
    list.removeValue(7);
    list.displayList();

    return 0;
}


/*


Inserting: 5, 3, 10, 7, 1, 6
List Forward:
{              0        :         1     :       0x55d0dcfe32e0 }
{ 0x55d0dcfe3340        :         3     :       0x55d0dcfe32c0 }
{ 0x55d0dcfe32e0        :         5     :       0x55d0dcfe3360 }
{ 0x55d0dcfe32c0        :         6     :       0x55d0dcfe3320 }
{ 0x55d0dcfe3360        :         7     :       0x55d0dcfe3300 }
{ 0x55d0dcfe3320        :        10     :                    0 }
List Backward:
{ 0x55d0dcfe3320        :        10     :                    0 }
{ 0x55d0dcfe3360        :         7     :       0x55d0dcfe3300 }
{ 0x55d0dcfe32c0        :         6     :       0x55d0dcfe3320 }
{ 0x55d0dcfe32e0        :         5     :       0x55d0dcfe3360 }
{ 0x55d0dcfe3340        :         3     :       0x55d0dcfe32c0 }
{              0        :         1     :       0x55d0dcfe32e0 }

Removing first element...
List Forward:
{              0        :         3     :       0x55d0dcfe32c0 }
{ 0x55d0dcfe32e0        :         5     :       0x55d0dcfe3360 }
{ 0x55d0dcfe32c0        :         6     :       0x55d0dcfe3320 }
{ 0x55d0dcfe3360        :         7     :       0x55d0dcfe3300 }
{ 0x55d0dcfe3320        :        10     :                    0 }

Removing last element...
List Forward:
{              0        :         3     :       0x55d0dcfe32c0 }
{ 0x55d0dcfe32e0        :         5     :       0x55d0dcfe3360 }
{ 0x55d0dcfe32c0        :         6     :       0x55d0dcfe3320 }
{ 0x55d0dcfe3360        :         7     :                    0 }

Removing value 7...
List Forward:
{              0        :         3     :       0x55d0dcfe32c0 }
{ 0x55d0dcfe32e0        :         5     :       0x55d0dcfe3360 }
{ 0x55d0dcfe32c0        :         6     :                    0 }



*/