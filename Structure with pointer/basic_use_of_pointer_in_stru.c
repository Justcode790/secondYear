#include<stdio.h>
#include<stdlib.h>
typedef struct stu{
    int age;
    int roll;
}stu;
int main(){
    stu *an;
    int n;

    printf("enter: ");
    scanf("%d",&n);

    an = (stu*)malloc(n*sizeof(stu));
    for(int i=0;i<n;i++){
        an[i].roll=i+1;
        an[i].age=i+20;
    }

    for(int i=0;i<n;i++){
        printf("Roll: ");
        printf("%d\n",an[i].roll);
        printf("age: ");
        printf("%d\n",an[i].age);
    }
    free(an);
    return 0;
}