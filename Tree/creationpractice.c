#include<stdio.h>
#include<malloc.h>

typedef struct node{
    struct node* left;
    int data;
    struct node* right;
}node;

node* createNode (int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}

node* insert(node* root, int data){
    if(root==NULL){
        root= createNode(data);
    }
    else{
        if(data<(root->data)){
            root->left = insert(root->left,data);
        }
        else if(data>(root->data)){
            root->right = insert(root->right,data);
        }
    }
}


void preorder(node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    node* root = NULL;
    int m,data;
    printf("Please enter the number of nodes you want to create: ");
    scanf("%d",&m);
    printf("Enter data: ");
    for(int i=0;i<m;i++){
        scanf("%d",&data);
        root = insert(root,data);
    }
    printf("preorder: ");
    preorder(root);
    printf("\n");
    printf("inorder: ");
    inorder(root);
    printf("\n");
    printf("postorder: ");
    postorder(root);
    printf("\n");

}