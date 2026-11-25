#include <stdio.h>
#include <stdlib.h>
// AVL Tree Node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
// Function to get maximum of two numbers
int max(int a, int b)
{
    return (a > b) ? a : b;
}
// Function to get height of node
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
// Create a new node
struct Node *newNode(int key)
{
    struct Node *node = malloc(sizeof(struct Node));
    if (node == NULL)
    {
        perror("Failed to allocate AVL node");
        exit(EXIT_FAILURE);
    }
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
// Right Rotation
struct Node* rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),
                height(y->right)) + 1;
    x->height = max(height(x->left),
                height(x->right)) + 1;
    return x;
}
// Left Rotation
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left),
    height(x->right)) + 1;
    y->height = max(height(y->left),
                height(y->right)) + 1;
    return y;
}
// Get Balance Factor
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
// AVL Insertion
struct Node *insert(struct Node *node, int key)
{
    // BST insertion
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    // Update height
    node->height = 1 + max(height(node->left),
    height(node->right));
    // Get balance factor
    int balance = getBalance(node);
    // LL Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    // RR Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    // LR Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // RL Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
// Inorder Traversal
void inorder(struct Node *root) {
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
// Preorder Traversal
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
// Main Function
int main()
{
    struct Node *root = NULL;
    int n, value, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("\nInorder Traversal (Sorted): ");
    inorder(root);
    printf("\nPreorder Traversal (AVL Tree): ");
    preorder(root);
    printf("\n");
    return 0;
}
// Created by rvu on 11/25/26.
//
