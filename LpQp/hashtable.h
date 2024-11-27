#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <stdexcept>
#include <iostream>

using namespace std;

enum Collision {
    LINEAR_PROBING,
    QUADRATIC_PROBING
};

class HashTable {
private:
    vector<list<int>> table;
    int tableSize;
    int numElements;
    Collision collision;

    int hashFunction(int key) const;
    void rehash();

public:
    HashTable(int size, Collision method);
    void insert(int key);
    bool search(int key) const;
    void remove(int key);
    void display() const;
};

#endif
