#include<stdio.h>
#define SIZE 10
#define EMPTY -1

int hashTable[SIZE];

// Initialize hash table
void initializeTable(){
    int i;
    for(i = 0; i < SIZE; i++){
        hashTable[i] = EMPTY;
    }
}

// Hash function
int hashFunction(int key){
    return key % SIZE;
}

// Insert using Quadratic Probing
void insertQuadratic(int key){
    int index = hashFunction(key);
    int i;

    for(i = 0; i < SIZE; i++){
        int newIndex = (index + i * i) % SIZE;

        if(hashTable[newIndex] == EMPTY){
            hashTable[newIndex] = key;
            printf("%d inserted at index %d\n", key, newIndex);
            return;
        }
    }

    printf("Hash table is full. Could not insert %d\n", key);
}

// Display hash table
void displayTable(){
    int i;
    printf("\nHash Table:\n");
    for(i = 0; i < SIZE; i++){
        if(hashTable[i] == EMPTY)
            printf("Index %d: EMPTY\n", i);
        else
            printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main(){
    initializeTable();

    insertQuadratic(23);
    insertQuadratic(43);
    insertQuadratic(13);
    insertQuadratic(27);
    insertQuadratic(33);

    displayTable();

    return 0;
}