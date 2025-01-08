#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct printjob{
    int id;
    char doc_name[100];
    int no_pages;
    char sub_date[50];
    struct printjob *next;
}printjob;


typedef struct queue{
    printjob *font;
    printjob *rear;
    int size;
}queue;



queue* initiate(){
    queue *q=(queue*)malloc(sizeof(queue));
    q->font=q->rear=NULL;
    q->size=0;
    return q;
}