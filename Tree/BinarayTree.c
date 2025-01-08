#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* CreatenewNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}

void insertIntoBinary(node** roots){
    int x;
    printf("Enter data: ");
    scanf("%d",&x);
    if(x==-1){
        return;
    }else{
        node* newnode = CreatenewNode(x);
        if(*roots==NULL){
            *roots=newnode;
            // return;
        }
        printf("going in left dirrection\n");
        insertIntoBinary(&(*roots)->left);
        printf("going in right dirrection\n");
        insertIntoBinary(&(*roots)->right);
    }
}


// node* searching(node* roots,int key){
//     node* parent;
//     if(roots==NULL){
//         return 0;
//     }
//     if(roots->data==key){
//         // printf("Yes Found %d and its address is %p",key,roots);
//         printf("%d",*parent->data);
//         return roots;
//     }
//     searching(roots->left,key);
//     searching(roots->right,key);
//     parent=roots;
// }

node* searching(node* roots, int key, node* parent) {
    if (roots == NULL) {
        return NULL;  // Return NULL if node not found
    }

    if (roots->data == key) {
        if (parent != NULL) {
            printf("Parent of %d is %d\n", key, parent->data);  // Print parent data if it exists
        } else {
            printf("%d is the root and has no parent.\n", key);  // Root node has no parent
        }
        return roots;  // Return the found node
    }

    // Search in the left subtree, passing current node as parent
    node* foundNode = searching(roots->left, key, roots);
    if (foundNode != NULL) {
        return foundNode;
    }

    // Search in the right subtree, passing current node as parent
    return searching(roots->right, key, roots);
}

// void deletion(node* roots,int key){
//     node* xxx = searching(roots,key);
//     node* parent = roots;
//     if(xxx!=NULL){
//         if(xxx->left == NULL && xxx->right==NULL){
//             free(xxx);

//         }
//     }
// }


void preorder(node* roots){
    if(roots==NULL){
        return;
    }
    printf("%d ",roots->data);
    preorder(roots->left);
    preorder(roots->right);
}

void inorder(node* roots){
    if(roots==NULL){
        return;
    }
    inorder(roots->left);
    printf("%d ",roots->data);
    inorder(roots->right);
}


int main(){
    node *roots=NULL;
    insertIntoBinary(&roots);
    preorder(roots);
    printf("\n");
    // inorder(roots);
    // printf("\n");
    // node *x= searching(roots,88);
    node *x = searching(roots, 88, NULL); 
    printf("%p",x);
    return 0;
}
