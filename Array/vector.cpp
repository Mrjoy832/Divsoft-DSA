#include<iostream>
using namespace std;

class vector{
    private:
    int *elements;
    int capacity;
    int size;

    public:
    vector(int initial=10){
        capacity=initial;
        size=0;
        elements=new int[capacity];
    }

    void push_back(int val){
        if(size==capacity){//if capacity fulls double it
            capacity*=2;
            int *newElements= new int[capacity];//create a new array 
            for(int i=0;i<size;i++){
                newElements[i]=elements[i];//tranferring into new array
            }
            delete[] elements;// delete the data to elements
            elements=newElements;// pointing to the same
        }
        elements[size++]=val;// then increase the size and put value
    }


    void pop_back(){
        if(size>0)--size;
    }

    int getSize(){
        return size;
    }

// to access via v[i] method used in line 52,55
    int operator[](int index){
        return elements[index];
    }
};

int main(){
    vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    // cout<<v.getSize();
    for(int i=0;i<v.getSize();i++)cout<<v[i]<<" ";
    cout<<endl;
    v.pop_back();
    for(int i=0;i<v.getSize();i++)cout<<v[i]<<" ";




}