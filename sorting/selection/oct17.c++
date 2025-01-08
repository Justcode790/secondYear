#include<iostream>
using namespace std;

int swap(int &a,int &b){
    int temp = a;
    a=b;
    b=temp;
}


void selection(int n, int a[]){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        swap(a[i],a[min]);
    }
}

void print(int n, int a[]){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int a[5]={5,2,1,0,4};
    selection(5,a);
    print(5,a);
    return 0;
}