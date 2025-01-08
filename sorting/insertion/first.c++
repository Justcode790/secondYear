#include<iostream>
using namespace std;

void insertion(int n, int a[]){
    for(int i=1;i<n;i++){
        int x=a[i];
        int j=i-1;
        while(j>=0 && a[j]>x){
            a[j+1]=a[j];
            j--;
        }
        a[j+1] =x;
    }
}

void print(int n, int a[]){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int a[5]={5,2,1,0,4};
    insertion(5,a);
    print(5,a);
    return 0;
}