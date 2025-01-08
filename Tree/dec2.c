#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    struct node* left;
    int data;
    struct node* right;
} node;

node* createNode(int x) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insertData(node** root, int arr[], int index, int n) {
    if (index >= n || arr[index] == -1) {
        return;
    }
    
    if (*root == NULL) {
        *root = createNode(arr[index]);
    }
    
    insertData(&(*root)->left, arr, index + 1, n);
    insertData(&(*root)->right, arr, index + 1, n);
}

void preorder(node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}


void postorder(node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}


void inorder(node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements (use -1 for null):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    node* root = NULL;
    insertData(&root, arr, 0, n);
    
    printf("Pre-order traversal: ");
    preorder(root);
    printf("\n");
    printf("in-order traversal: ");
    inorder(root);
    printf("\n");
    printf("post-order traversal: ");
    preorder(root);
    printf("\n");

    return 0;
}
