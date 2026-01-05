#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10
struct Node
{
    int key;
    struct Node* next;
};

struct Node* hashTable[TABLE_SIZE];

int hash(int key){
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hash(key);

    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}


bool search(int key) {
    int index = hash(key);
    struct Node* curr = hashTable[index];

    while (curr != NULL) {
        if (curr->key == key)
            return true;
        curr = curr->next;
    }
    return false;
}

void deleteKey(int key) {
    int index = hash(key);
    struct Node* curr = hashTable[index];
    struct Node* prev = NULL;

    while (curr != NULL) {
        if (curr->key == key) {
            if (prev == NULL)
                hashTable[index] = curr->next;
            else
                prev->next = curr->next;

            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}


int main() {
    // Initialize table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Insert values
    insert(15);
    insert(25);
    insert(35);   // collides with 15 if TABLE_SIZE = 10
    insert(5);

    // Search tests
    printf("Search 25: %s\n", search(25) ? "Found" : "Not Found");
    printf("Search 99: %s\n", search(99) ? "Found" : "Not Found");

    // Delete test
    deleteKey(25);
    printf("After deletion, search 25: %s\n",
           search(25) ? "Found" : "Not Found");

    return 0;
}
