/*2.Write a C program to delete a node having no child from a binary search tree.*/
#include <stdio.h>
#include <stdlib.h>
// Structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to insert a new node
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
// Function to delete a node with no child
struct Node* deleteNode(struct Node* root, int value) {
    // Base case: if the tree is empty
    if (root == NULL) {
        return root;
    }
    // Search for the node to be deleted
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // If the node has no child or only one child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
    }
    return root;
}
// Function to print the inorder traversal of the tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
int main() {
	int i;
    struct Node* root = NULL;
    int elements[] = { 5, 3, 7, 1, 4, 6, 8 };
    int n = sizeof(elements) / sizeof(elements[0]);
    // Inserting elements into the tree
    for (i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }
    printf("Inorder traversal before deletion: ");
    inorderTraversal(root);
    printf("\n");
    int deleteValue = 4;
    root = deleteNode(root, deleteValue);
    printf("Inorder traversal after deletion of %d: ", deleteValue);
    inorderTraversal(root);
    printf("\n");
    // Freeing dynamically allocated memory
    // (not essential in this simple program, but good practice)
    free(root);
    return 0;
}
