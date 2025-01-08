#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node* left;
    int data;
    struct node* right;
}node;

node* createNode(int x){
    node* newNode = (node*)malloc(sizeof(node));
    newNode.data=x;
    newNode->left=newNode->right=NULL;
    return newNode;
}

void insertData(node** roots, int x){
    if(x==-1){
        return;
    }else{
        node newnode= createNode(x);
        if(*roots==NULL){
            *roots=newnode;
        }
        insertData(&(*roots)->left,x);
        insertData(&(*roots)->right,x);
    }
}

void preorder(node *roots){
    if(roots==NULL){
        return;
    }
    printf("%d ",roots.data);
    preorder(roots->left);
    preorder(roots->right);
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d" ,&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    node roots=NULL;
    for(int i=0;i<n;i++){
        insertData(&roots,arr[i]);
    }
    preorder(roots);
    return 0;
}