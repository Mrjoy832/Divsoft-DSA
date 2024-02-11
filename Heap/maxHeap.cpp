//Love Babbar: https://youtu.be/NKJnHewiGdc?si=F4DyWrIaVsDUoFy9

//MAxheap doesnot care like BST i.e. left one lesser and right one greater
// it only have to fills up from left to right 
#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
public:
int arr[100];
int size;

MaxHeap(){
arr[0]=-1;
size=0;
}

//insertion in maxheap: T.C: logN
void insert(int val){
size+=1;
int index=size;
arr[index]=val;

while(index>1){
    int parent=index/2;
    if(arr[parent]<arr[index]){
        swap(arr[parent],arr[index]);
        index=parent;
    }
    else{
        return;
    }
}

}

//Deletion:means to delete largest num or the main root:/// TC - logN
void deleteFromHeap(){
    if(size==0){
        cout<<"nothing to delete"<<endl;
        return;
    }

// put last element into 1st index
    arr[1]=arr[size];
    size--;

    //take root to its correct position:
    int i=1;
    while(i<size){
        int left=2*i;
        int right=2*i+1;

        if(left<size and arr[i]<arr[left]){
            swap(arr[i],arr[left]);
            i=left;
        }
        else if(right<size and arr[i]<arr[right]){
            swap(arr[i],arr[right]);
        }
        else {
            return;
        }
    }
}

//printing the heap:
void print(){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

};

int main(){
    MaxHeap h;
    h.insert(1);
    h.insert(5);
    h.insert(3);
    h.insert(2);
    h.insert(4);
    h.insert(8);

    h.print();
    h.deleteFromHeap();
    h.print();
}


// Read Heapify algo to rest from the video at last: 31.00 min - rest