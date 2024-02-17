#include <iostream>
using namespace std;

class Deque {
    static const int size = 100;
    int frontIndex;
    int rearIndex;
    int elements[size];

public:
    Deque() : frontIndex(-1), rearIndex(-1) {}

    // Method to insert an element at the front of the deque
    void insertFront(int value) {
        if (isEmpty()) {
            frontIndex = 0;
            rearIndex = 0;
        } else if (frontIndex == 0) {
            cout << "Deque overflow at front" << endl;
            return;
            
        } else {
            frontIndex--;
        }
        elements[frontIndex] = value;
    }

    // Method to insert an element at the rear of the deque
    void insertRear(int value) {
        if (isEmpty()) {
            frontIndex = 0;
            rearIndex = 0;
        } else if (rearIndex == size - 1) {
            cout << "Deque overflow at rear" << endl;
            return;
        } else {
            rearIndex++;
        }
        elements[rearIndex] = value;
    }

    // Method to remove an element from the front of the deque
    int removeFront() {
        if (isEmpty()) {
            cout << "Deque underflow at front" << endl;
            return -1;
        }
        int removedElement = elements[frontIndex];
        if (frontIndex == rearIndex) {
            // Reset indices when deque becomes empty
            frontIndex = -1;
            rearIndex = -1;
        } else {
            frontIndex++;
        }
        return removedElement;
    }

    // Method to remove an element from the rear of the deque
    int removeRear() {
        if (isEmpty()) {
            cout << "Deque underflow at rear" << endl;
            return -1;
        }
        int removedElement = elements[rearIndex];
        if (frontIndex == rearIndex) {
            // Reset indices when deque becomes empty
            frontIndex = -1;
            rearIndex = -1;
        } else {
            rearIndex--;
        }
        return removedElement;
    }

    // Method to check if deque is empty
    bool isEmpty() {
        return frontIndex == -1;
    }

    // Method to print all elements in the deque
    void print() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        cout << "Deque elements are: ";
        for (int i = frontIndex; i <= rearIndex; ++i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    dq.insertFront(2);
    dq.insertRear(3);
    dq.insertFront(1);
    dq.insertRear(4);
    dq.print();

    cout << "Removed front element: " << dq.removeFront() << endl;
    cout << "Removed rear element: " << dq.removeRear() << endl;
    dq.print();

    cout << "Is deque empty? " << (dq.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
