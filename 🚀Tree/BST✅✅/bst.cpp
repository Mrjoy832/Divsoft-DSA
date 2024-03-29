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

class BST{
    
    Node*root;

//inserting a node
    Node* insertBST(Node*root, int val){
        if(root==NULL)return new Node(val);
        Node*cur=root;
        while(true){
            if(cur->data<=val){
                if(cur->right!=NULL)cur=cur->right;

                else {
                    cur->right=new Node(val);
                    break;
                }
            }

            else{
                if(cur->left!=NULL)cur=cur->left;
                else{
                    cur->left=new Node(val);
                    break;
                }
            }
        }
        return root;
    }


/*// insert Recursive:

Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

*/

//traversal Inorder
    void inOrder(Node*root){
        if(root==NULL)return;

        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }

// Search:
bool searchRecursive(Node*cur,int k){
    if(cur==NULL)return false;

    if(k==cur->data)return true;

    if(k<cur->data)return searchRecursive(cur->left,k);
    else return searchRecursive(cur->right,k);
}
//iterative Search
Node* search(Node*root , int val){
    while(root!=NULL and root->data!=val){
        root= val < root->data?root->left:root->right;
    }
    return root;
}


// Ceil value: smallest value in tree which is greater than key
int findCeil(Node*root,int key){
    int ceil=-1;
    while(root!=NULL){
        if(root->data==key){
            ceil=root->data;
            return ceil;
        }

        if(key>root->data)root=root->right;

        else{
            ceil=root->data;
            root=root->left;
            
        }
    }
    return ceil;
}

// floor value: greatest value in tree which is smaller than key
int findFloor(Node*p, int key){
    int floor=-1;
    while(p!=NULL){
        if(p->data==key){
            floor=p->data;
            return floor;
        }

        if(key>p->data){
            floor=p->data;
            p=p->right;
        }

        else {
            p=p->left;
        }
    }
    return floor;
}

// Find minimum element:
Node * findMin(Node*t){
    if(t==NULL)return NULL;
    else if(t->left==NULL)return t;
    else return findMin(t->left);
}
//Find Maximum element:
Node * findMax(Node*t){
    if(t==NULL)return NULL;
    else if(t->right==NULL)return t;
    else return findMax(t->right);
}


//check BST or not:
bool validBST(Node*p){
    return isValid(root, INT_MIN, INT_MAX);
}

bool isValid(Node*t,int min,int max){
if(t==NULL)return true;
if(t->data>=max or t->data<=min)return false;

return isValid(t->left, min, t->data)
and isValid(t->right, t->data, max);
}


//LCA of two nodes:Using recursion 
Node* LCA(Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    int cur = root->data;
    
    if (cur < p && cur < q) {
        return LCA(root->right, p, q);
    } else if (cur > p && cur > q) {
        return LCA(root->left, p, q);
    } else {
        return root;
    }
}


//deleting a node: O(height)

//1. to find the righest node
Node* findLastRight(Node*root){
    if(root->right==NULL)return root;

    return findLastRight(root->right);
}
//2.adding the right child to the keys left's rigthest node->right
Node* helper(Node*root){

    //je node del krbo tar left na thakle right subtree return
    if(root->left==NULL)return root->right;

        //je node del krbo tar right na thakle left subtree return
    else if(root->right==NULL)return root->left;

    Node*rightChild=root->right;
    Node*lastRight=findLastRight(root->left);
    lastRight->right=rightChild;
    return root->left;
}
//3. 
Node* deleteNode(Node*root, int key){
if(root==NULL)return NULL;

if(root->data==key)return helper(root);
while(root!=NULL){
    if(root->data>key){
        if(root->left!=NULL and root->left->data==key){
            root->left=helper(root->left);break;
        }else{
            root=root->left;
        }
    }
    else{
        if(root->right!=NULL and root->right->data==key){
            root->right=helper(root->right);
            break;
        }else{
            root=root->right;
        }
    }
}
}


////////////////////
public:
BST(){
    root=NULL;
}

void insert(int v){
    root=insertBST(root,v);
}

void inOrder(){
    inOrder(root);
}

bool search(int v){
    return searchRecursive(root,v);
}

int ceilValue(int k){
    return findCeil(root,k);
}

int floorVal(int k){
    return findFloor(root,k);
}

int minimum(){
    return findMin(root)->data;
}

int maximum(){
    return findMax(root)->data;
}

bool BSTorNOT(){
    return validBST(root);
}

Node* LCAval(int p,int q){
    return LCA(root,p,q);
}

void DeleteNode(int k){
     deleteNode(root,k);
}
};



int main(){
     BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);

    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    bst.insert(10);
    bst.insert(35);
    bst.insert(42);

    bst.inOrder();//20 30 40 50 60 70 80 
    cout<<endl;
    bst.DeleteNode(30);
    bst.inOrder();
    cout<<bst.ceilValue(45)<<endl;//50
    cout<<bst.floorVal(45)<<endl;//40
    
    cout<<bst.search(50)<<endl;//1

    cout<<bst.minimum()<<" " <<bst.maximum()<<endl;//20 80

    cout<<bst.BSTorNOT()<<endl;//1




    cout<<bst.LCAval(30,60)->data;//50
}