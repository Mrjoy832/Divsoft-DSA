
// TC - n  , SC- n(for skewed tree)

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node*left,*right;
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

// check for balanced binary tree:
//1. 
bool balanced(Node*root){
    return height(root)!=-1;
}
//2.
int height(Node*root){
    if(root==NULL)return 0;

    int lh=height(root->left);
    if(lh==-1)return -1;

    int rh=height(root->right);
    if(rh==-1)return -1;

    if(abs(lh-rh)>1)return -1;

    return 1+max(lh,rh);
}
};


int main(){
    BinaryTree bt;
    bt.root=new Node(1);
    bt.root->right=new Node(2);
    bt.root->left=new Node(3);
    bt.root->left->right=new Node(4);
    bt.root->left->left=new Node(5);
    bt.root->left->left->left=new Node(7);
    bt.root->left->left->right=new Node(6);
    
    cout<<bt.balanced(bt.root);//0

}