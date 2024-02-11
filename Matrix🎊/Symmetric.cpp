#include<bits/stdc++.h>
using namespace std;

class Symmetric{
int size;
int **data;
public:
Symmetric(int sizes){
    size=sizes;
    data=new int*[size];

    for(int i=0;i<size;i++){
        data[i]=new int[size];
        for(int j=0;j<size;j++){
            data[i][j]=0;//// Initialize all elements to zero
        }
    }
}

//setting the val
void set(int i,int j,int val){
    if(i>=0 and i<size and j>=0 and j<size){
        data[i][j]=val;
        data[j][i]=val;
    }
    else{
        cout<<"index out of bound"<<endl;
    }
}

//getting value
int get(int i,int j){
    if (i >= 0 && i < size && j >= 0 && j < size) {
            return data[i][j];
        } else {
            std::cout << "Error: Index out of bounds." << std::endl;
            return -1; // Return a default value indicating error
        }
}
};

int main(){
        // Create a 3x3 symmetric matrix
    Symmetric matrix(3);

    // Set values in the symmetric matrix
    matrix.set(0, 0, 1);
    matrix.set(0, 1, 2);
    matrix.set(0, 2, 3);
    matrix.set(1, 1, 4);
    matrix.set(1, 2, 5);
    matrix.set(2, 2, 6);

    //print the value
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<matrix.get(i,j)<<" ";
        }
        cout<<endl;
    }

}
/*
1 2 3 
2 4 5 
3 5 6 
*/