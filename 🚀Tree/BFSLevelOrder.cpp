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

//BFS
vector<vector<int>>levelOrder(Node*root){
    vector<vector<int>>ans;
    if(root==NULL)return ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            Node*p=q.front();
            q.pop();
            if(p->left!=NULL)q.push(p->left);
            if(p->right!=NULL)q.push(p->right);
            level.push_back(p->data);
        }
    ans.push_back(level);
    }
    return ans;
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

    vector<vector<int>>ans=bt.levelOrder(bt.root);
    for(int i=0;i<ans.size();i++){
        for(auto it:ans[i])cout<<it<<" ";
    }
}