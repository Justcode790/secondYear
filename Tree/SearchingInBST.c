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


int searching(node* roots,int key){
    if(roots==NULL){
        return 0;
    }
    if(roots->data==key){
        return roots;
    }
    if(key<roots->data){
        searching(roots->left,key);
    }
    if(key>roots->data){
        searching(roots->right,key);
    }
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
    node* roots=NULL;
    insertionBST(&roots,5);
    insertionBST(&roots,2);
    insertionBST(&roots,89);
    insertionBST(&roots,88);
    printf("Data Of first tree\n");
    preorder(roots);
    printf("\n");
    inorder(roots);
    printf("\n");
    postorder(roots);
    printf("\n");
    
    int *x = searching(roots,89);
    if(!x){
        printf("not found");
    }else{
        printf("found %p",x);
    }
    return 0;
}

