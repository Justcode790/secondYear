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

void deletion(node* roots,int key){
    
    if(roots==NULL){
        return;
    }
    node* parent = NULL;
    node* presentNode = roots;

    while(presentNode->data!=key){
        parent=presentNode;
        if(key<presentNode->data){
            presentNode = presentNode->left;
            }
        if(key>presentNode->data){
            presentNode = presentNode->right;
            }
    }

    if(presentNode==NULL || presentNode->left!=NULL || presentNode->right!=NULL){
        return;
    }
    
    if(parent->left==presentNode){
            parent->left=NULL;
            }
        else{
            parent->right=NULL;
            }
        free(presentNode);
}

int maxm(node* roots){
    if(roots==NULL){
        return;
    }
}

void deletion(node* roots,int key){
    
    if(roots==NULL){
        return;
    }
    else if(key<roots->data){
       roots->left = deletion(roots->left,key);
    }
    else if(key>roots->right){
        roots->right = deletion(roots->right,key);
    }
    
    if(roots->data==key){
        if((roots->left ==NULL) && (roots->left ==NULL)){
                free(roots);
        }
        else if((roots->left==NULL) && (roots->right!=NULL)){
            node* temp = roots->right;
            free(roots);
            return temp;
        }
        else if((roots->left!=NULL) && (roots->right==NULL)){
            node* temp = roots->left;
            free(roots);
            return temp;
        }

    }


    
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

int searching(node* roots,int key){
    // node* parent =NULL;
    if(roots==NULL){
        return 0;
    }
    if(roots->data==key){
        return 1;
    }
    if(key<roots->data){
        searching(roots->left,key);
    }
    if(key>roots->data){
        searching(roots->right,key);
    }
    return -1;
    // parent=roots;
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
    insertionBST(&roots,1);
    printf("Data Of first tree\n");
    preorder(roots);
    printf("\n");
    inorder(roots);
    printf("\n");
    postorder(roots);
    printf("\n");
    
    // int x = searching(roots,88);
    // if(x==-1){
    //     printf("not found");
    // }else{
    //     printf("found %d",x);
    // }

    // deletion(&roots,88);
    deletion(roots,1);
    preorder(roots);
    printf("\n");
    inorder(roots);
    return 0;
}

