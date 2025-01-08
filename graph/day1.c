#include <stdio.h>
#include <stdlib.h>

// Definition of a node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to perform inorder traversal of a BST and print the result
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Function to insert a node into a BST
Node* insert(Node* root, int data) {
    if (root == NULL) return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to merge two BSTs
Node* mergeBSTs(Node* root1, Node* root2) {
    if (root1 == NULL) return root2;
    if (root2 == NULL) return root1;

    // Insert elements of the second BST into the first BST
    root1 = insert(root1, root2->data);
    root1 = mergeBSTs(root1, root2->left);
    root1 = mergeBSTs(root1, root2->right);

    return root1;
}

int main() {
    // Create two BSTs
    Node* root1 = newNode(3);
    root1->left = newNode(1);
    root1->right = newNode(5);
    root1->left->right = newNode(2);
    root1->right->left = newNode(4);

    Node* root2 = newNode(8);
    root2->left = newNode(7);
    root2->right = newNode(9);
    root2->left->left = newNode(6);

    // Merge the two BSTs
    Node* mergedRoot = mergeBSTs(root1, root2);

    // Print the inorder traversal of the merged BST
    printf("Inorder traversal of the merged BST: ");
    inorder(mergedRoot);
    printf("\n");

    return 0;
}
 
 (1, 'y2', 'january'),
(2, 'y2', 'february'),
(3, 'y2', 'march'),
(4, 'y2', 'april'),
(5, 'y2', 'may'),
(6, 'y2', 'june'),
(7, 'y2', 'july'),
(8, 'y2', 'august'),
(9, 'y2', 'september'),
(10, 'y2', 'october'),
(11, 'y2', 'november'),
(12, 'y2', 'december');
