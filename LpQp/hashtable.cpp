#include "HashTable.h"

HashTable::HashTable(int size, Collision method)
    : tableSize(size), collision(method), numElements(0) {
    table.assign(size, list<int>());
}

int HashTable::hashFunction(int key) const {
    return key % tableSize;
}

void HashTable::insert(int key) {
    if ((float)numElements / tableSize >= 0.7) {
        rehash();
    }

    int index = hashFunction(key);
    int i = 0;

    while (!table[(index + i) % tableSize].empty()) {
        if (collision == LINEAR_PROBING) {
            i++;
        } else if (collision == QUADRATIC_PROBING) {
            i = i * i;
        }

        if (i >= tableSize) {
            throw overflow_error("Table is full");
        }
    }

    table[(index + i) % tableSize].push_back(key);
    numElements++;
}

void HashTable::rehash() {
    vector<list<int>> oldTable = table;
    tableSize *= 2;
    table.assign(tableSize, list<int>());
    numElements = 0;

    for (const auto& bucket : oldTable) {
        for (int key : bucket) {
            insert(key);
        }
    }
}

bool HashTable::search(int key) const {
    int index = hashFunction(key);
    int i = 0;

    while (!table[(index + i) % tableSize].empty()) {
        for (int element : table[(index + i) % tableSize]) {
            if (element == key) {
                return true;
            }
        }

        if (collision == LINEAR_PROBING) {
            i++;
        } else if (collision == QUADRATIC_PROBING) {
            i = i * i;
        }

        if (i >= tableSize) {
            return false;
        }
    }

    return false;
}

void HashTable::remove(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (!table[(index + i) % tableSize].empty()) {
        table[(index + i) % tableSize].remove(key);

        if (collision == LINEAR_PROBING) {
            i++;
        } else if (collision == QUADRATIC_PROBING) {
            i = i * i;
        }

        if (i >= tableSize) {
            return;
        }
    }
}

void HashTable::display() const {
    for (int i = 0; i < tableSize; ++i) {
        cout << "Índice " << i << ": ";
        for (int key : table[i]) {
            cout << key << " -> ";
        }
        cout << "nullptr\n";
    }
}
