#include<bits/stdc++.h>
using namespace std;

class Matrix{
    int row;
    int col;
    int **data;

    public:

//creating the schema for matrix:
    Matrix(int rows,int cols){
        row=rows;
        col=cols;
        data=new int * [rows];
        for(int i=0;i<rows;i++){
            data[i]=new int[cols];
        }
    }

    //setting value at specific pos
    void set(int i,int j,int val){
        if(i>=0 and i<row and j>=0 and j<col){
                data[i][j]=val;
        }
        else {
            cout<<"Index out of bounds";
        }
    }

    //method to ge value at specific pos
    int get(int i,int j){
        if(i>=0 and i<row and j>=0 and j<col){return data[i][j];}

        else{ cout<<"index out of bound"; return -1;}
    }
};

int main(){
   // Create a 3x3 matrix
    Matrix matrix(3, 3);

    // Set values in the matrix
    matrix.set(0, 0, 1);
    matrix.set(0, 1, 2);
    matrix.set(0, 2, 3);
    matrix.set(1, 0, 4);
    matrix.set(1, 1, 5);
    matrix.set(1, 2, 6);
    matrix.set(2, 0, 7);
    matrix.set(2, 1, 8);
    matrix.set(2, 2, 9);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<matrix.get(i,j)<<" ";
        }
        cout<<endl;
    }

}
/*
1 2 3 
4 5 6 
7 8 9 
*/


// General basic implementation of matrix:
// int main() {
//   int m,n;
//   cin>>m>>n;
//   int arr[m][n];
//   for(int i=0;i<m;i++){
//       for(int j=0;j<n;j++){
//           cin>>arr[i][j];
//       }
//   }
//   for(int i=0;i<m;i++){
//       for(int j=0;j<n;j++){
//           cout<<arr[i][j]<<" ";
//       }
//       cout<<endl;
//   }
// }