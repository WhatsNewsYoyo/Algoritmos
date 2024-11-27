#include "HashTable.h"

int main() {
    int tableSize = 10;
    HashTable hashTable(tableSize, LINEAR_PROBING);

    hashTable.insert(5);
    hashTable.insert(15);
    hashTable.insert(25);
    hashTable.insert(2);
    hashTable.insert(10);

    cout << "Tabla Hash:\n";
    hashTable.display();

    cout << "\nBuscar 15: " << (hashTable.search(15) ? "Encontrado" : "No encontrado") << "\n";
    cout << "Buscar 9: " << (hashTable.search(9) ? "Encontrado" : "No encontrado") << "\n";

    hashTable.remove(15);
    cout << "\nDespués de eliminar 15:\n";
    hashTable.display();

    return 0;
}
