#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(){
        data=0;
        next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class Linkedlist{
Node *head;
public:
Linkedlist(){
    head=NULL;
}


// insert at begining
void insertBegin(int n){
    Node * p=new Node(n);
    p->next=head;
    head=p;
}

// insert at end
void insertEnd(int n){
    Node *p=new Node(n);
    if(head==NULL){
        head=p;
    }
    else{
        Node * t=head;
        while(t->next!=NULL)t=t->next;

        t->next=p;
    }

}

// delete begin
void deleteBegin(){
    if(head==NULL){cout<<"empty list,nothing to del";}
    else{
        Node *t=head;
        head=head->next;
        delete t;
    }
}

//delete end
void deleteEnd(){
    if(head==NULL){
        cout<<"empty list,nothing to del";
    }
    else{
        Node*t=head;
        while(t->next->next!=NULL){t=t->next;}
        delete t->next;
        t->next=NULL;
    }
}

//delete from any particular index:
void deleteAtIndex(int pos){
    Node *p=head;
    Node*q=NULL;
    for(int i=0;i<pos-1;i++){
        q=p;
        p=p->next;
    }
    q->next=p->next;
    delete p;
}


// print elements
void print(){
    Node *t=head;
    while(t!=NULL){
        cout<<t->data<<" ";
        t=t->next;
    }cout<<endl;
}

//searching
int search(int k){
    Node *p=head;
    while(p->next!=NULL){
        if(p->data==k)return 1;
        p=p->next;
    }
    return -1;
}


//insert at any index:
void insertatIndex(int n,int pos){
Node*p=new Node(n);
Node*t=head;
for(int i=0;i<pos-1;i++){
    t=t->next;
}
p->next=t->next;
t->next=p;
}


//reverse linkedlist
void reverse(){
    Node * cur=head;
    Node *prev=NULL,*nex=NULL;

    while(cur!=NULL){
        //store next
        nex=cur->next;
        // Reverse current node's pointer
        cur->next=prev;
         // Move pointers one position ahead.
        prev=cur;
        cur=nex;
    }
    head=prev;
}

//detect cycle:
bool cycle(){
    Node* slow=head;
    Node*fast=head;
    while(fast!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)return true;
    
}
return false;
}

};





int main(){
    Linkedlist l;
    l.insertEnd(2);
    l.insertEnd(3);
    l.insertEnd(4);
    l.insertEnd(5);
    l.insertBegin(1);
l.print();
// l.deleteBegin();l.deleteEnd();
l.insertatIndex(7,4);
l.print();
// cout<<l.search(9);
l.reverse();
l.print();
l.deleteAtIndex(4);
l.print();
cout<<l.cycle();//0

}