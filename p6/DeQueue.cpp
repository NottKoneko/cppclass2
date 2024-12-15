#include <iostream>
using namespace std;

class Dequeue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int size;

public:
    // Constructor
    Dequeue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Destructor
    ~Dequeue() {
        delete[] arr;
    }

    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Insert an element at the left
    void insertLeft(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot insert at the left.\n";
            return;
        }
        if (front == -1) { // First insertion
            front = rear = 0;
        } else if (front == 0) { // Wrap around
            front = capacity - 1;
        } else {
            front--;
        }
        arr[front] = value;
        size++;
    }

    // Insert an element at the right
    void insertRight(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot insert at the right.\n";
            return;
        }
        if (rear == -1) { // First insertion
            front = rear = 0;
        } else if (rear == capacity - 1) { // Wrap around
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
        size++;
    }

    // Remove an element from the left
    void removeLeft() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot remove from the left.\n";
            return;
        }
        cout << "Removed: " << arr[front] << " from left\n";
        if (front == rear) { // Single element
            front = rear = -1;
        } else if (front == capacity - 1) { // Wrap around
            front = 0;
        } else {
            front++;
        }
        size--;
    }

    // Remove an element from the right
    void removeRight() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot remove from the right.\n";
            return;
        }
        cout << "Removed: " << arr[rear] << " from right\n";
        if (front == rear) { // Single element
            front = rear = -1;
        } else if (rear == 0) { // Wrap around
            rear = capacity - 1;
        } else {
            rear--;
        }
        size--;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue: ";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);
        cout << endl;
    }
};

int main() {
    Dequeue dq(5);

    dq.insertRight(10);
    dq.insertRight(20);
    dq.insertLeft(5);
    dq.insertLeft(3);
    dq.insertRight(30);
    dq.display();

    dq.removeLeft();
    dq.display();

    dq.removeRight();
    dq.display();

    dq.insertLeft(15);
    dq.insertRight(25);
    dq.display();

    dq.insertRight(35); // Attempt to insert in a full queue

    return 0;
}

/*
Queue: 3 5 10 20 30 
Removed: 3 from left
Queue: 5 10 20 30 
Removed: 30 from right
Queue: 5 10 20 
Queue: 15 5 10 20 25 
Queue is full. Cannot insert at the right.
*/