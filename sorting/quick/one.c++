#include<iostream>
using namespace std;

void print(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int b,int e){
    int p=b;
    while(b<e){
        do{
             b++;
        } while (a[p]>a[b]);
        do{
            e--;
        }while(a[p]<a[e]);

        if(b < e) {
            swap(&a[b], &a[e]);
        }
    }
    int temp = a[p];
    a[p]=a[e];
    a[e]=temp;
    return e;
}
void quicksort(int a[], int b,int e){
    if(b<e){
        int x=partition(a,b,e);
        quicksort(a,b,x);
        quicksort(a,x+1,e);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n);
    print(a,n);
    return 0;
}