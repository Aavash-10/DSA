#include<stdio.h>
#define SIZE 10
#define EMPTY -1

int hashTable[SIZE];
 //Hash table
 void initializeTable(){
 	int i;
 	for(i=0;i<SIZE;i++){
 		hashTable[i] = EMPTY;
	 }
 }
 //Hash function
 int hashFunction(int key){
 	return key % SIZE;
 }
 //Insert
 
 void insertLinear(int key){
 	int index = hashFunction(key);
 	int i;
 	
 	for(i=0;i<SIZE;i++){
 		int newIndex = (index + i) % SIZE;
 		
 		if(hashTable[newIndex]==EMPTY){
 			hashTable[newIndex] = key;
 			printf("%d inserted at index %d\n",key,newIndex);
 			return;
		 }
	 }
	 printf("Hash table is full.Could not insert %d\n",key);
 }
 //Display hash table
 void displayTable(){
 	int i;
 	printf("\nHash Table:\n");
 	for(i=0;i<SIZE;i++){
 		if(hashTable[i]==EMPTY)
 		printf("Index %d:EMPTY\n",i);
 		else
 		printf("Index %d:%d\n",i,hashTable[i]);
	 }
 }
 
int main(){
	initializeTable();
	
	insertLinear(57);
	insertLinear(23);
	insertLinear(88);
	insertLinear(25);
	insertLinear(17);
	
	displayTable();
	return 0;
}
// lab report see for comments