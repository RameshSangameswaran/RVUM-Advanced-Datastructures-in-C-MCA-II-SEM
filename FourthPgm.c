#include <stdio.h>
#include <stdlib.h>
// Structure for a node
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
// Insert at beginning
void insert(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));//
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Node inserted successfully.\n");
}
// Delete a node by value
void deleteNode(int value)
{
    struct Node *temp = head, *prev = NULL;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    // If head node contains the value
    if (temp != NULL && temp->data == value)
    {
        head = temp->next;
        free(temp);
        printf("Node deleted successfully.\n");
        return;
    }
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Element not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted successfully.\n");
}
// Traverse the linked list
void traverse()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Search an element
void search(int value)
{
    struct Node *temp = head;
    int position = 1;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Element found at position %d\n", position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element not found.\n");
}
// Main Function
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n----- Singly Linked List Operations -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 3:
                traverse();
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
// Created by rvu on 11/25/26.
//
