#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node *left,*right;
Node(int val){
    data=val;
    left=right=NULL;
}
};

class BinaryTree{
public:
Node *root;
BinaryTree(){
    root=NULL;
}

//int max depth or height:
int maxDepth(Node*root){
    if(root==NULL)return 0;
    int lh=maxDepth(root->left);
    int rh=maxDepth(root->right);

    return 1+max(lh,rh);
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

    cout<<bt.maxDepth(bt.root);
}
//3
