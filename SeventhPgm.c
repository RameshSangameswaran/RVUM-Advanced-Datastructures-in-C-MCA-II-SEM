#include <stdio.h>
#include <stdlib.h>
// Structure for BST Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
// Create New Node
struct Node* createNode(int value)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Insert Node
struct Node* insert(struct Node* root, int value)
{
    if(root == NULL)
        return createNode(value);
    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);
    return root;
}
// Search Node
struct Node* search(struct Node* root, int key)
{
    if(root == NULL || root->data == key)
        return root;
    if(key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}
// Find Minimum Value Node
struct Node* findMin(struct Node* root)
{
    while(root && root->left != NULL)
        root = root->left;
    return root;
}
// Delete Node
struct Node* deleteNode(struct Node* root, int key)
{
if(root == NULL)
    return root;
if(key < root->data)
    root->left = deleteNode(root->left, key);
else if(key > root->data)
    root->right = deleteNode(root->right, key);
else
{
    // Node with only one child or no child
    if(root->left == NULL)
    {
        struct Node* temp = root->right;
        free(root);
        return temp;
    }
    else if(root->right == NULL)
    {
        struct Node* temp = root->left;
        free(root);
        return temp;
    }
    // Node with two children
    struct Node* temp = findMin(root->right);
    root->data = temp->data;
    root->right =
      deleteNode(root->right, temp->data);
}
return root;
}
// Inorder Traversal
void inorder(struct Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
// Preorder Traversal
void preorder(struct Node* root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
// Postorder Traversal
void postorder(struct Node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
// Main Function
int main()
{
    struct Node* root = NULL;
    int choice, value;
    while(1)
    {
        printf("\n===== BST MENU =====\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Node inserted successfully.\n");
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if(search(root, value))
                    printf("Element found.\n");
                else
                    printf("Element not found.\n");
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Node deleted successfully.\n");
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
// Created by rvu on 11/25/26.
//
