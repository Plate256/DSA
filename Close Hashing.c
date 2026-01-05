#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

int hashTable[TABLE_SIZE];

int hash(int key){
    return key % TABLE_SIZE;
}

void insert (int key){
    int index = hash(key);

    while (hashTable[index] != EMPTY && hashTable[index] != DELETED)
    {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = key;
}

bool search(int key){
    int index = hash(key);
    int start = index;

    while (hashTable[index] != EMPTY)
    {       
        if (hashTable[index] == key)
        {
            return true;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == start)
        {
            break;
        }
        
    }
    return false;
}

void delete(int key) {
    int index = hash(key);
    int start = index;

    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key) {
            hashTable[index] = DELETED;
            return;
        }

        index = (index + 1) % TABLE_SIZE;
        if (index == start)
            break;
    }
}


int main() {
    // Initialize table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }

    // Insert values
    insert(15);
    insert(25);
    insert(35);   // will probe forward
    insert(5);

    // Search tests
    printf("Search 35: %s\n", search(35) ? "Found" : "Not Found");
    printf("Search 99: %s\n", search(99) ? "Found" : "Not Found");

    // Delete test
    delete(35);
    printf("After deletion, search 35: %s\n",
           search(35) ? "Found" : "Not Found");

    return 0;
}
