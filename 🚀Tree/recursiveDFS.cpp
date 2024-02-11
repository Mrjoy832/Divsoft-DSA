// DFS with some other functions

#include<bits/stdc++.h>
using namespace std;

//node class for new nodes
class Node{
    public:
int data;
Node*left,*right;


Node(int val){
    data=val;
    left=right=NULL;}
};

//binaryTree class for tree structure
class BinaryTree{
    public:
    Node*root;

    BinaryTree(){
        root=NULL;
    }

// Preorder
void preOrder(Node*p){
    if(p==NULL)return;

    cout<<p->data<<" ";
    preOrder(p->left);
    preOrder(p->right);
}

//postOrder
void postOrder(Node*p){
    if(p==NULL)return;

    postOrder(p->left);
    postOrder(p->right);
    cout<<p->data<<" ";
}

//Inorder
void InOrder(Node*p){
    if(p==NULL)return;

    InOrder(p->left);
    cout<<p->data<<" ";
    InOrder(p->right);
}


//search for a value
bool search(Node*root,int k){
    if(root==NULL)return false;

    if(root->data==k)return true;

    return search(root->left,k) or search(root->right,k);
}

// Add a node:
 // Add a node
    void addNode(Node* root, int val) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            if (!temp->left) {
                temp->left = new Node(val);
                break;
            } else
                q.push(temp->left);
            if (!temp->right) {
                temp->right = new Node(val);
                break;
            } else
                q.push(temp->right);
        }
    }
};

int main(){
    BinaryTree tree;
    tree.root=new Node(1);
    tree.root->left= new Node(2);
    tree.root->right= new Node(3);
    tree.root->right->left= new Node(4);


    tree.preOrder(tree.root);
    cout<<endl;

    tree.InOrder(tree.root);
    cout<<endl;

    tree.postOrder(tree.root);
}