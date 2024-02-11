#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() : data(0), next(NULL), prev(NULL) {}
    Node(int data) : data(data), next(NULL), prev(NULL) {}
};

class DoublyCircularLinkedList {
    Node* head;

public:
    DoublyCircularLinkedList() : head(NULL) {}

    // insert at beginning
    void insertBegin(int n) {
        Node* p = new Node(n);
        if (!head) {
            head = p;
            head->next = head;
            head->prev = head;
        } else {
            p->next = head;
            p->prev = head->prev;
            head->prev->next = p;
            head->prev = p;
            head = p;
        }
    }

    // insert at end
    void insertEnd(int n) {
        Node* p = new Node(n);
        if (!head) {
            head = p;
            head->next = head;
            head->prev = head;
        } else {
            p->next = head;
            p->prev = head->prev;
            head->prev->next = p;
            head->prev = p;
        }
    }

    // delete beginning
    void deleteBegin() {
        if (!head) {
            cout << "empty list, nothing to delete";
        } else {
            Node* temp = head;
            if (head->next == head) {
                // Only one node in the list
                head = NULL;
            } else {
                head->prev->next = head->next;
                head->next->prev = head->prev;
                head = head->next;
            }
            delete temp;
        }
    }

    // delete end
    void deleteEnd() {
        if (!head) {
            cout << "empty list, nothing to delete";
        } else {
            Node* temp = head->prev;
            if (temp == head) {
                // Only one node in the list
                head = NULL;
            } else {
                temp->prev->next = head;
                head->prev = temp->prev;
            }
            delete temp;
        }
    }

    // print elements from the beginning
    void printForward() {
        if (!head) {
            cout << "Doubly circular linked list is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }

    // print elements from the end
    void printBackward() {
        if (!head) {
            cout << "Doubly circular linked list is empty." << endl;
            return;
        }

        Node* temp = head->prev;
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != head->prev);

        cout << endl;
    }

    // search for an element
    int search(int k) {
        if (!head) {
            return -1;
        }

        Node* temp = head;
        do {
            if (temp->data == k) return 1;
            temp = temp->next;
        } while (temp != head);

        return -1;
    }

    // new method based on the given prototype
    void performCustomOperation() {
        // Your custom operation code here
        cout << "Performing custom operation." << endl;
    }
};

int main() {
    DoublyCircularLinkedList dcll;
    dcll.insertEnd(2);
    dcll.insertEnd(3);
    dcll.insertEnd(4);
    dcll.insertEnd(5);
    dcll.insertBegin(1);
    cout << "Forward: ";
    dcll.printForward();
    cout << "Backward: ";
    dcll.printBackward();
    dcll.deleteBegin();
    dcll.deleteEnd();
    cout << "Forward after deletion: ";
    dcll.printForward();
    cout << "Backward after deletion: ";
    dcll.printBackward();
    cout << dcll.search(9) << endl;

    // New method call
    dcll.performCustomOperation();

    return 0;
}
