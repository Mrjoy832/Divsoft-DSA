
// int n;
// int *p=new int[n];

#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insert(int arr[], int &size , int pos , int val){
    if(pos<0 or pos>size){
        cout<<"invalid"<<endl;
    }
    else {
        for(int i=size;i>pos;i--){
            arr[i]=arr[i-1];
        }
        arr[pos]=val;
        size++;
    }
}

void reverse(int arr[], int size){
    int start=0,end=size-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void printSubarray(int arr[], int size){
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            for(int k=i;k<=j;k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
}

void deleteElement(int arr[] , int &size , int pos){
    for(int i=pos;i<size-1;i++){
        arr[pos]=arr[pos+1];
    }
    size--;
}

int main(){
    const int maxSize=100;
    int arr[maxSize];
    int size=0;

    insert(arr,size,0,1);
    insert(arr,size,1,2);
    insert(arr,size,2,3);
    insert(arr,size,3,4);

    print(arr,4);
    deleteElement(arr,size,2);
    print(arr,4);
}