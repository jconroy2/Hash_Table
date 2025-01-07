# Hash_Table
This program implements a hash table with separate chaining to manage integer values efficiently. The hash table uses a direct hash function  ℎ ( 𝑥 ) = 𝑥 h(x)=x to compute the hash code for each value. Collisions are resolved using linked lists, ensuring that multiple values hashing to the same index are stored without overwriting.

PROBLEM STATEMENT:
Write a program to implement a hash table with separate chaining.
The hash table stores integer values.
The hash function is h(x) = x. For example,
• if the integer value is x = 27, then the hash code is h(27) = 27.
• if the integer value is x = 194, then the hash code is h(194) = 194.
• if the integer value is x = 583, then the hash code is h(583) = 583.
The hash table uses separate chaining to resolve collisions.
Program Description:
1. Prompt the user to enter the size of the hash table (i.e. number of buckets).
2. Prompt the user to select an operation (insert or remove).
3. Prompt the user to specify an integer value.
4. Perform the selected operation using the specified integer value.
5. Output the contents of the hash table and the hash table load.
6. Repeat steps 2 – 5 until the user selects “exit”.
Program Requirements:
1. The program must use the structures defined below.
2. The program must use the functions listed below.
3. Other functions may be included, but are not required.
Additional helpful information:
• A set does not contain any duplicate values. Therefore, a value should not be inserted into
the hash table if it already exists in the hash table.
• The size of the hash table is used to determine the bucket into which to insert a new value.
• The number of items in the hash table is used to determine the load of the hash table.


Structure definition for a Linked List:
typedef struct LinkedList {
 Node_t *head;
 Node_t *tail;
} LinkedList_t;
Structure definition for a Node:
typedef struct Node {
 int data;
 struct Node *next;
} Node_t;
Structure definition for a Hash Table:
typedef struct HashTable {
 LinkedList *arrayOfLL;
 int tableSize;
 int numOfItems;
} HashTable_t;
Function prototypes:
1. Node_t* CreateNode(int value);
2. LinkedList_t* CreateArrayOfLists(int size);
3. HashTable_t* CreateTable(int size);
4. int CalculateTableIndex(HashTable_t* table, int value);
5. void InsertTable(HashTable_t* table, int index, int value);
 or
 void InsertTable(HashTable_t* table, int value);
6. void RemoveTable(HashTable_t* table, int index, int value);
 or
 void RemoveTable(HashTable_t* table, int value);
7. void PrintTable(Hashtable_t* table);

Sample program run:
Specify the size of the hash table: 6
Select the operation to perform:
1. Insert a value
2. Remove a value
3. Exit
Select an option: 1
Enter a value: 14
0:
1:
2: 14
3:
4:
5:
load = 0.167
Select the operation to perform:
1. Insert a value
2. Remove a value
3. Exit
Select an option: 1
Enter a value: 35
0:
1:
2: 14
3:
4:
5: 35
load = 0.333
