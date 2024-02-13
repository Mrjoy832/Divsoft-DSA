#include<bits/stdc++.h>
using namespace std;

const int size=10;
class HashTable{
int *table;
public:
HashTable(){
    table=new int[size];
    for(int i=0;i<size;i++){
        table[i]=-1;
    }
}

~HashTable(){delete []table;}

int hashFunction(int key){
    return key%size;
}

void insert(int key){
    int index=hashFunction(key);

//linear probing
    while(table[index]!=-1){
        index=(index+1)%size;
    }
    table[index]=key;
}

bool search (int key){
    int index=hashFunction(key);

    while(table[index]!=-1){
        if(table[index]==key)return true;

// Linear probing to continue searching
        index=(index+1)%size;
    }
    return false;
}

void display(){
    for(int i=0;i<size;i++){
        cout<<"index "<<i<<": ";
        if(table[i]!=-1){
            cout<<table[i];
            cout<<endl;
        }
    }
}
};


int main(){
    HashTable h;
    h.insert(2);
    h.insert(5);
    h.insert(15);
    h.insert(25);
    h.insert(3);
    h.insert(12);
    cout<<"hash Table content:"<<endl;
    h.display();

    int key=15;
    if(h.search(key)){cout<<"Key " << key << " found in the hash table." << endl;}
    else 
    {cout<<"Key " << key << " Not found in the hash table." << endl;}
}




// In C++ hashing, the term "loading factor" refers to the ratio of the
//  number of elements stored in a hash table to the total number of
//   slots or buckets available in the hash table. It is a measure of
//  how full the hash table is.

// To maintain efficient performance, it is often desirable to keep the 
// loading factor within a certain range. Common practice suggests keeping
//  the loading factor below a certain threshold (usually around 0.7) to
//  minimize the chances of collisions and maintain acceptable performance levels.

// ​
