#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

struct node* minm(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* maxm(struct node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

void preorder(struct node* root) {
    // if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    // }
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


int main() {
    struct node* root = NULL;
    int n, m;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter data: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        root = insert(root, m);
    }

    // printf("Inorder traversal: ");
    // inorder(root);
    // printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    // printf("Postorder traversal: ");
    // postorder(root);
    // printf("\n");

    // printf("Minimum value: %d\n", minm(root)->data);
    // printf("Maximum value: %d\n", maxm(root)->data);

    // printf("Deleting node 4...\n");
    // root = delete(root, 4);

    // printf("Inorder traversal after deletion: ");
    // inorder(root);
    // printf("\n");

    return 0;
}
