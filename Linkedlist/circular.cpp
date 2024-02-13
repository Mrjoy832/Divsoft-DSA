// Circular Linked list

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
Node*head;
public:
Linkedlist(){
    head=NULL;
}

//insert at begining
void insertAtBegin(int n){
    Node*p=new Node(n);
    if(!head){
        p->next=p;//// Point to itself if it's the only node
    }
    else{
        p->next=head;
        Node*t=head;
        //have to reach end bcz u to have to add last node->next=first node
        while(t->next!=head)t=t->next;

        t->next=p;
    }
    head=p;
}

//insert at end
void insertEnd(int n){
    Node*p=new Node(n);
    if(!head){
        head=p;
        p->next=head;
    }
    else{
        Node*t=head;
        while(t->next!=head)t=t->next;

        t->next=p;
        p->next=head;
    }
}

//insert at index:
void insertAt(int pos,int n){
    Node *p=new Node(n);
    Node *t=head;
    for(int i=0;i<pos-1;i++){
        t=t->next;
    }
    p->next=t->next;
    t->next=p;
}

//delete from begining
void deleteBegin(){
    if(!head){cout<<"empty list";}
    else{
        Node *t=head;
        while(t->next!=head)t=t->next;

        if(t==head){
            //then only one node in this list
            delete t;
            head=NULL;
        }
        else{
            t->next=head->next;
            delete head;
            head=t->next;
        }
    }
}

//print elements
void print(){
    if(!head){
        cout<<"empty"<<endl;
    }
    Node *t=head;
    do{
        cout<<t->data<<" ";
        t=t->next;
    }while(t!=head);
cout<<endl;
}

//search elements
int search(int k){
    if(!head)return -1;

    Node *t=head;
    do{
        if(t->data==k)return 1;
        t=t->next;
    }while(t!=head);

    return -1;

}

//delete element from end
void deleteEnd(){
    if(!head)cout<<"empty list";

    else{
        Node *t=head;
        Node *prev=NULL;

        while(t->next!=head){
            prev=t;
            t=t->next;
        }
        if(prev==NULL){
            //only one node in list
            delete t;
            head=NULL;
        }
        else{
            prev->next=head;
            delete t;
        }
    }
}
};

int main(){
    Linkedlist l;
    l.insertEnd(2);
    l.insertEnd(3);
    l.insertEnd(4);
    l.insertEnd(5);
    
    l.insertEnd(6);
    
    l.insertAtBegin(1);

    l.print();
    cout<<l.search(5)<<endl;
    l.deleteBegin();
    l.print();
    l.deleteEnd();
    l.print();
    l.insertAt(3,7);
    l.print();


}