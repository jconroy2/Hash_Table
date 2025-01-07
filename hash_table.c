#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node_t;

typedef struct LinkedList
{
    Node_t *head;
    Node_t *tail;
} LinkedList_t;

typedef struct HashTable
{
    LinkedList_t *arrayofLL;
    int tableSize;
    int numOfItems;
} HashTable_t;

int hash(int x)
{
    return x;
}

Node_t *CreateNode(int value)
{
    Node_t *node = malloc(sizeof(Node_t));

    if (node)
    {
        node->data = value;
        node->next = NULL;
    }

    return node;
}

LinkedList_t *CreateArrayOfLists(int size)
{
    return calloc(size, sizeof(LinkedList_t));
}

HashTable_t *CreateTable(int size)
{
    HashTable_t *table = malloc(sizeof(HashTable_t));

    if (table)
    {
        table->arrayofLL = CreateArrayOfLists(size);
        table->numOfItems = 0;
        table->tableSize = size;
    }

    return table;
}

int CalculateTableIndex(HashTable_t *table, int value)
{
    return hash(value) % table->tableSize;
}

void InsertTable(HashTable_t *table, int value)
{
    Node_t *node;
    int index = CalculateTableIndex(table, value);
    LinkedList_t *list = &table->arrayofLL[index];

    // Check for duplicate
    for (node = list->head; node; node = node->next)
    {
        if (node->data == value)
        {
            return;
        }
    }

    // Insert new value
    node = CreateNode(value);
    if (list->head)
    {
        // Insert at the end
        list->tail->next = node;
        list->tail = node;
    }
    else
    {
        list->head = node;
        list->tail = node;
    }

    table->numOfItems++;
}

void RemoveTable(HashTable_t *table, int value)
{
    int index = CalculateTableIndex(table, value);
    LinkedList_t *list = &table->arrayofLL[index];

    // Find the node and remove it
    for (Node_t *prev = NULL, *node = list->head; node; prev = node, node = node->next)
    {
        // Check if it matches the value
        if (node->data == value)
        {
            // Remove this node
            if (prev)
            {
                prev->next = node->next;
            }
            else
            {
                list->head = node->next;
            }

            // Node is at the end
            if (!node->next)
            {
                list->tail = prev;
            }

            free(node);
            table->numOfItems--;
            return;
        }
    }
}

void PrintTable(HashTable_t *table)
{
    for (int i = 0; i < table->tableSize; i++)
    {
        printf("\n%d: ", i);

        // Print the linked list
        for (Node_t *node = table->arrayofLL[i].head; node; node = node->next)
        {
            printf("%d", node->data);

            if (node->next)
            {
                printf(",");
            }
        }
    }

    printf("\n\nload = %.3f\n\n", (float)table->numOfItems / (float)table->tableSize);
}



int ask_operation()
{
    int operation;

    printf("\nSelect the operation to perform:\n\n");
    printf("1. Insert a value\n");
    printf("2. Remove a value\n");
    printf("3. Exit\n");
    printf("\nSelect an option: ");

    scanf("%d", &operation);

    return operation;
}

int enter_value()
{
    int value;

    printf("\nEnter a value: ");

    scanf("%d", &value);

    return value;
}

void delete_linked_list(LinkedList_t *ll)
{
    // Delete the nodes
    for (Node_t *node = ll->head, *next; node; node = next)
    {
        next = node->next;
        free(node);
    }
}

void delete_table(HashTable_t *table)
{
    // Delete the linked lists
    for (int i = 0; i < table->tableSize; i++)
    {
        delete_linked_list(&table->arrayofLL[i]);
    }

    free(table->arrayofLL);
    free(table);
}

int main()
{
    int size;

    printf("Specify the size of the hash table: ");
    scanf("%d", &size);

    HashTable_t *table = CreateTable(size);

    for (;;)
    {
        switch (ask_operation())
        {
        case 1:
            InsertTable(table, enter_value());
            PrintTable(table);
            break;
        case 2:
            RemoveTable(table, enter_value());
            PrintTable(table);
            break;
        case 3:
            printf("\nGood-bye.\n");
            delete_table(table);
            return 0;
        }
    }
}
