#include <iostream>

const int TABLE_SIZE = 10;

class HashTable {
private:
    int table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = -1;
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        int i = 1;

        // Quadratic probing to find the next available slot
        while (table[index] != -1) {
            index = (originalIndex + i * i) % TABLE_SIZE;
            ++i;
        }

        table[index] = key;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int originalIndex = index;
        int i = 1;

        // Quadratic probing to search for the key
        while (table[index] != -1) {
            if (table[index] == key)
                return true;

            index = (originalIndex + i * i) % TABLE_SIZE;
            ++i;
        }

        return false;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            std::cout << "Index " << i << ": ";
            if (table[i] != -1)
                std::cout << table[i];
            std::cout << std::endl;
        }
    }
};

int main() {
    HashTable hashTable;

    hashTable.insert(5);
    hashTable.insert(15);
    hashTable.insert(25);

    std::cout << "HashTable Contents:" << std::endl;
    hashTable.display();

    int searchKey = 15;
    if (hashTable.search(searchKey))
        std::cout << "Key " << searchKey << " found in the hash table." << std::endl;
    else
        std::cout << "Key " << searchKey << " not found in the hash table." << std::endl;

    return 0;
}

/*
const int size = 10;

class HashTable {
    int *table;
public:
    HashTable() {
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1;
        }
    }

    ~HashTable() {
        delete []table;
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int i = 1;

        // Quadratic probing
        while (table[index] != -1) {
            index = (index + i * i) % size;
            i++;
        }
        table[index] = key;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int i = 1;

        // Quadratic probing
        while (table[index] != -1) {
            if (table[index] == key)
                return true;

            index = (index + i * i) % size;
            i++;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            if (table[i] != -1) {
                cout << table[i];
            }
            cout << endl;
        }
    }
};

*/