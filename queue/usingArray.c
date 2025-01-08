#include<stdio.h>
#define max 5

int array[max];
int rear=-1;
int font=-1;

void display(){
    if(font==-1){
        printf("Queue is empty\n");
        return;
    }
    for(int i=font;i<=rear;i++){
        printf("%d ",array[i]);
    }
}
void enqueue(int data){
    if(rear==max-1){
        // display();
        printf("queue is full\n");
        return;
    }
    // if(rear==-1){
    //     rear++;
    //     array[rear]=data;
    //     font++;
    //     return;
    // }
    rear+=1;
    array[rear]=data;
    if(font==-1){
        font++;
    }
}

int dequeue(){
    if(font==-1){
        printf("Queue is empty\n");
        return 0;
    }
    int x=array[font];
    font++;
    return x;
}


int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    // enqueue(6);
    display();
    printf("\n");
    dequeue();
    display();
    return 0;
}