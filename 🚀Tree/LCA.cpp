#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node* left,*right;
Node(int val){
    data=val;
    left=right=NULL;
}
};

class BinaryTree{
    public:
Node*root;
BinaryTree(){
    root=NULL;
}

//LCA: TC -- N , SC---N
Node* LCA(Node*root, Node*p , Node*q){
    if(root==NULL or root==p or root==q)return root;

    Node*left=LCA(root->left,p,q);
    Node*right=LCA(root->right,p,q);

    if(left==NULL)return right;
    else if(right==NULL)return left;
    else return root;
}
};

int main(){
    BinaryTree bt;
    bt.root=new Node(1);
    bt.root->left=new Node(2);
    bt.root->left->right=new Node(5);
    bt.root->left->left=new Node(4);
    bt.root->right=new Node(3);
    bt.root->right->right=new Node(7);
    bt.root->right->left=new Node(6);

    cout<<bt.LCA(bt.root, bt.root->left->left,bt.root->right->left)->data;//1
}