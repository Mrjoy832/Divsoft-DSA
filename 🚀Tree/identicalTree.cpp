
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

// identical tree or not:
bool isSameTree(Node*p,Node*q){
    if(p==NULL or q==NULL)return (p==q);

    return (p->data==q->data) and isSameTree(p->left,q->left) and 
    isSameTree(p->right,q->right);
}
};


int main(){
    // Example usage
    BinaryTree tree1, tree2;
    tree1.root = new Node(1);
    tree1.root->left = new Node(2);
    tree1.root->right = new Node(3);

    tree2.root = new Node(1);
    tree2.root->left = new Node(2);
    tree2.root->right = new Node(3);

    if (tree1.isSameTree(tree1.root, tree2.root))
        cout << "The binary trees are identical.";
    else
        cout << "The binary trees are not identical.";
    
}