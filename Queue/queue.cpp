#include<bits/stdc++.h>
using namespace std;

class Queue{
    static const int size=100;
    int front,rear;
    int elements[size];

    public:
    Queue(){
        front=-1;
        rear=-1;
    }

    //enque:
    void push(int n){
        if(rear==size-1){
            cout<<"overflow";
            return;
        }
// **if queue is empty must do it ****
        if(isEmpty()){front=0;}

        rear+=1;
        elements[rear]=n;
    }

    //dequeue
    int pop(){
        if(isEmpty()){
            cout<<"underflow";
            return -1;
        }

        int element=elements[front++];
        //**
        if(front>rear){
            front=-1;
            rear=-1;
        }
        return element;
    }

    //check empty
    bool isEmpty(){
        return front==-1;
    }

    //print
    void print(){
        if(isEmpty()){
            cout<<"empty queue";
            return;
        }
        cout<<"queue elements are";
        for(int i=front;i<=rear;i++){
                cout<<elements[i]<<" ";
        }
        cout<<endl;
    }

    //print front
    void frontElement(){
        if(isEmpty()){cout<<"empty"; return;}

        cout<<"front is:"<<elements[front];
    }

    //print rear
    void rearElement(){
        if(isEmpty()){cout<<"empty"; return;}

        cout<<"rear is:"<<elements[rear];
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.print();
    q.pop();
    q.print();
    q.frontElement();
    q.rearElement();
}