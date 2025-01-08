#include<stdio.h>
#include<stdlib.h>

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

void insertionBT(node** roots,int data){
    node* root = createNode(data);
    if(*roots==NULL){
        *roots=root;
        return;
    }
    if(data<(*roots)->data){
        insertionBT(&(*roots)->left,data);
        return;
    }
    if(data>(*roots)->data){
        insertionBT(&(*roots)->right,data);
        return;
    }
}

int countNoOfLeaf(node* root){
    if(root==NULL){
        return 0;
    }
    if((root->left==NULL) && (root->right==NULL ) ){
        return 1;
    }
    return countNoOfLeaf(root->left)+countNoOfLeaf(root->right);
}
int maxm(int a, int b){
    if(a>b){
        return a;
    }else return b;
}
int height =0;
int heightOftree(node* root){
    if(root==NULL){
        return 0;
    }
    if((root->left==NULL) && (root->right==NULL ) ){
        return 1;
    }
    return 1+maxm(heightOftree(root->left),heightOftree(root->right));

}

int countNoofnode(node* root){
    if(root==NULL){
        return 0;
    }
    else{
        return 1+countNoofnode(root->left)+countNoofnode(root->right);
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
    insertionBT(&roots,5);
    insertionBT(&roots,2);
    insertionBT(&roots,7);
    insertionBT(&roots,1);
    preorder(roots);
    printf("\n");
    inorder(roots);
    printf("\n");
    postorder(roots);
    printf("\n");
    printf("%d ",countNoOfLeaf(roots));
    printf("\n");
    printf("%d ",countNoofnode(roots));
    printf("\n");
    printf("%d ",heightOftree(roots));

    return 0;
}

