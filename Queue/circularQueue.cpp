#include<bits/stdc++.h>
using namespace std;

class CircularQueue{
    static const int size=100;
    int front,rear;
    int elements[size];
public:
CircularQueue(){
    front=rear=-1;
}

//enque
void push(int val){
    if((rear+1)%size==front){
        cout<<"overflow";
    }
    else{
        if(isEmpty())front=0;

//inserting into next index
        rear=(rear+1)%size;
        elements[rear]=val;
    }

}

//deque
int pop(){
if(isEmpty()){cout<<"underflow";
return -1;
}
int ele=elements[front];
if(front==rear){
    // Reset indices when queue becomes empty
        front=rear=-1;
    }
    // else move front to 1 step ahead
    else front=(front+1)%size;

return ele;
}

bool isEmpty(){
    return front==-1;
}

void print(){
    if(isEmpty()){cout<<"Empty Queue:";
    return;}
    cout<<"Queue Elements:";
    int i=front;
  

for(int i=front;i<=rear;i=(i+1)%size){
    cout<<elements[i]<<" ";
}
}
};

int main(){
    CircularQueue cq;
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);

    cq.print();
    cq.pop();
    cq.print();
}