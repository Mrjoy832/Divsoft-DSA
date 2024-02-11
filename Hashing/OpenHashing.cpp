#include <iostream>

const int TABLE_SIZE = 10;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class HashTable {
private:
    Node* table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = nullptr;
    }

    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);

        Node* newNode = new Node(key);

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            // Insert at the beginning of the linked list
            newNode->next = table[index];
            table[index] = newNode;
        }
    }

    bool search(int key) {
        int index = hashFunction(key);

        Node* current = table[index];

        while (current != nullptr) {
            if (current->data == key)
                return true;

            current = current->next;
        }

        return false;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            std::cout << "Index " << i << ": ";
            Node* current = table[i];
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    HashTable hashTable;

    hashTable.insert(5);
    hashTable.insert(15);
    hashTable.insert(25);
    hashTable.insert(2);
    hashTable.insert(3);

    std::cout << "HashTable Contents:" << std::endl;
    hashTable.display();

    int searchKey = 15;
    if (hashTable.search(searchKey))
        std::cout << "Key " << searchKey << " found in the hash table." << std::endl;
    else
        std::cout << "Key " << searchKey << " not found in the hash table." << std::endl;

    return 0;
}
