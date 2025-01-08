#include<iostream>
using namespace std;

//  to print the sorted array

void print(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

void merge(int a[],int b,int mid, int e){
    int temp[e-b+1] , index=0;
    int left=b,right=mid+1;

    // to check and sort if two element is greater or smaller and store it somewhere

    while(left <= mid && right <= e ){
        if(a[left]<a[right]){
            temp[index]=a[left];
            index++;
            left++;
        }
        else{
            temp[index]=a[right];
            index++; 
            right++;
        }
    }

    // to add remaining element in sorted array

    while(left<=mid){
        temp[index]=a[left];
        index++,left++;
    }

    // to add remaining element in sorted array
    
    while(right<=e){
        temp[index]=a[right];
        index++,right++;
    }

    // to arrange sorted array in main array

    index = 0;
    while(b<=e){
        a[b]=temp[index];
        b++, index++;
    }

}
void mergeSort(int a[], int b,int e){
    if(b==e){
        return;
    }
    int mid=b+(e-b)/2;
    mergeSort(a,b,mid);
    mergeSort(a,mid+1,e);
    merge(a,b,mid,e);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergeSort(a,0,n-1);
    print(a,n);
    return 0;
}