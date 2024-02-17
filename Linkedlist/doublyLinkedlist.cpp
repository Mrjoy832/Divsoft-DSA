#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next,*prev;

    Node(){
    data=0;
    next=prev=NULL;
    }

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

class Linkedlist{

Node*head;
public:
Linkedlist(){
    head=NULL;
}

//insert at begin
void insertBegin(int n){
    Node*p=new Node(n);
    if(!head){head=p;}
    else{
        p->next=head;
        head->prev=p;
        head=p;
    }
}

//insert at end:
void insertEnd(int n){
    Node*p=new Node(n);
    if(!head)head=p;
    else{
        Node*t=head;
        while(t->next!=NULL)t=t->next;

        t->next=p;
        p->prev=t;
    }
}

//print from begin:
void printForward(){
    if(!head){
        cout<<"doubly linkedlist is empty"<<endl;
        return;
    }
    Node*t=head;
    while(t!=NULL){
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<endl;
}
//print from end:
void printBackward(){
    if(!head){
        cout<<"doubly linkedlist is empty"<<endl;
        return;
    }
    Node*t=head;
    //to reach at end for traversing from last
    while(t->next!=NULL)t=t->next;
    
    while(t!=NULL){
        cout<<t->data<<" ";
        t=t->prev;
    }
    cout<<endl;
}

//search:
int search(int k){
    if(!head)return -1;

    Node*t=head;
    while(t!=NULL){
        if(t->data==k)return 1;

        t=t->next;
    }
    return -1;
}

//del from begin:
void deleteBegin(){
    if(!head)cout<<"empty";
    else{
        Node*t=head;
        head=head->next;
        
        if(head)head->prev=NULL;

        delete t;
    }
}

//del from end
void deleteEnd(){
    if(!head)cout<<"empty list";
    else{
        Node*t=head;
        while(t->next!=NULL)t=t->next;

        if(t->prev)t->prev->next=NULL;
        else head=NULL;

        delete t;
    }
}
};

int main(){
    Linkedlist l;
    l.insertEnd(2);
    l.insertEnd(3);
    l.insertEnd(4);
    l.insertEnd(5);
    l.insertBegin(1);

    l.printForward();
    l.printBackward();

    l.deleteBegin();
    l.deleteEnd();
    l.printForward();
}