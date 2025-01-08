#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void insertionBST(node** roots,int data){
    node* root = createNode(data);
    if(*roots==NULL){
        *roots=root;
        return;
    }
    if(data<(*roots)->data){
        insertionBST(&(*roots)->left,data);
        return;
    }
    if(data>(*roots)->data){
        insertionBST(&(*roots)->right,data);
        return;
    }
}

bool isSame(node* t1, node* t2){
    if(t1==NULL && t2 == NULL){
        return 1;
    }
    if(t1==NULL  || t2==NULL){
        return 0;
    }
    if(t1->data!=t2->data){
        return 0;
    }
    return (isSame(t1->left,t2->left) && isSame(t1->right,t2->right));
}



void preorder(node* root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}


int main(){
    node* roots1=NULL;
    node* roots2=NULL;
    insertionBST(&roots1,5);
    insertionBST(&roots1,2);
    insertionBST(&roots1,89);
    insertionBST(&roots1,88);
    printf("Data Of first tree\n");
    preorder(roots1);
    printf("\n");
    inorder(roots1);
    printf("\n");
    postorder(roots1);
    printf("\n");
    insertionBST(&roots2,5);
    insertionBST(&roots2,2);
    insertionBST(&roots2,89);
    insertionBST(&roots2,88);
    printf("Data Of second tree\n");
    preorder(roots2);
    printf("\n");
    inorder(roots2);
    printf("\n");
    postorder(roots2);
    printf("\n");
    int x = isSame(roots1,roots2);
    printf("%d",x);

    return 0;
}

