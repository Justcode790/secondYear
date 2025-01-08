#include<iostream>
using namespace std;

void bubble(int n, int a[]){
    for(int j=0;j<n;j++){
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                int temp = a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
}

void print(int n, int a[]){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int a[5]={5,2,1,0,4};
    bubble(5,a);
    print(5,a);
    return 0;
}