#include <iostream>
#include <list>
#include <vector>

using namespace std;

class HashTable {
    int TABLE_SIZE;
    vector<list<int>> table;

    // Hash function to map keys to table indices
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    // Constructor to initialize the hash table with a given size
    HashTable(int size) : TABLE_SIZE(size) {
        table.resize(TABLE_SIZE);
    }

    // Insert a key into the hash table
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Search for a key in the hash table
    bool search(int key) {
        int index = hashFunction(key);
        for (int element : table[index]) {
            if (element == key) {
                return true;
            }
        }
        return false;
    }

    // Remove a key from the hash table
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    // Display the contents of the hash table
    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "Index " << i << ": ";
            for (int element : table[i]) {
                cout << element << " -> ";
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht(10);

    // Insert keys into the hash table
    ht.insert(5);
    ht.insert(15);
    ht.insert(8);
    ht.insert(18);

    // Display the hash table
    ht.display();

    // Search for a key in the hash table
    if (ht.search(15)) {
        cout << "Key 15 found.\n";
    } else {
        cout << "Key 15 not found.\n";
    }

    return 0;
}
