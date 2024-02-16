
// For dynamic Stack:
/*
 int* elements;

 elements= new int[size];

 stack st(100);

*/


#include <iostream>
using namespace std;

class Stack {
    static const int size = 100;
    int topIndex; // Changed variable name to avoid naming conflict
    int elements[size];

public:
    // Constructor to initialize a stack
    Stack() {
        topIndex = -1;
    }

    // Method to push:   TC - 1
    void push(int value) {
        if (topIndex == size - 1) {
            cout << "Stack overflow";
            return;
        }
        topIndex++;
        elements[topIndex] = value;
    }

    // Method for pop:     TC - 1
    int pop() {
        if (topIndex == -1) {
            cout << "Stack underflow";
            return -1;
        }
        int poppedValue = elements[topIndex];
        topIndex--;
        return poppedValue; // Return the popped value
    }

    // Method for search:     TC- N
    int search(int k) {
        for (int i = topIndex; i >= 0; i--) {
            if (elements[i] == k) {
                return i; // Return the index where the element is found
            }
        }
        return -1; // Return -1 if element is not found
    }

    // Check if empty:     TC - 1
    bool isEmpty() {
        return topIndex == -1;
    }

    // Print all elements:    TC - N
    void print() {
        if (topIndex == -1)
            cout << "Empty" << endl;
        else {
            cout << "Elements are:" << endl;
            for (int i = topIndex; i >= 0; i--) {
                cout << elements[i] << " ";
            }
            cout << endl;
        }
    }

    // Method to get the top element: TC - 1
    int top() {
        if (topIndex == -1) {
            cout << "Stack is empty";
            return -1;
        }
        return elements[topIndex];
    }
};

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.print();
    cout << "Index of 4: " << st.search(4) << endl;
    st.pop();
    st.print();
    cout << "Is stack empty? " << st.isEmpty() << endl;

    cout << "Top element: " << st.top() << endl;
    return 0;
}
