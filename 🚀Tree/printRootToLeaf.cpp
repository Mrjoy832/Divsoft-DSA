
//TC-n , sc-n

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
//get path from root to leaf:
bool getPath(Node*root, vector<int>&arr, int x){
    if(!root)return false;

    arr.push_back(root->data);
    if(root->data==x)return true;

    if(getPath(root->left,arr,x) or getPath(root->right,arr,x))return true;

    arr.pop_back();
    return false;
}


vector<int>path(Node*p, int x){
vector<int>arr;
if(p==NULL)return arr;

getPath(p,arr,x);
}
////////
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

    vector<int>arr=bt.path(bt.root, 6);
    for(auto it:arr)cout<<it<<" ";

    
}