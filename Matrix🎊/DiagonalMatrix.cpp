#include<bits/stdc++.h>
using namespace std;

class DiagonalMatrix{
int size;
int *data;

public:
DiagonalMatrix(int size){
    this->size=size;
    data=new int[size];
    //Initialize diagonal elements to 0
    for(int i=0;i<size;i++)data[i]=0;
}

//set value 
void set(int i,int j,int val){
    if(i==j and i>=0 and j<size){
        if(i==j){
            data[j]=val;//// Set only diagonal elements
        }
        else{
            cout<<"Error: Non-diagonal elements cannot be modified." ;
        }
    }

    else{
        cout<<"index out of bound";
    }
}


//get value 
 // Method to get value at a specific position
    int get(int i, int j) const {
        if (i >= 0 && i < size && j >= 0 && j < size) {
            if (i == j) {
                return data[i]; // Return diagonal elements
            } else {
                return 0; // Return zero for non-diagonal elements
            }
        } else {
            std::cout << "Error: Index out of bounds." << std::endl;
            return -1; // Return a default value indicating error
        }
    }
};

int main(){
     // Create a 3x3 diagonal matrix
    DiagonalMatrix matrix(3);

    // Set values in the diagonal matrix
    matrix.set(0, 0, 1);
    matrix.set(1, 1, 2);
    matrix.set(2, 2, 3);

    // Get and print values from the diagonal matrix
    std::cout << "Diagonal Matrix:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix.get(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
/* 
1 0 0 
0 2 0 
0 0 3 


Using a double pointer (**data) to represent a diagonal matrix is also feasible. 
However, it's important to consider the memory layout and efficiency of the implementation.

In the case of a diagonal matrix, the main diagonal elements are the only ones that have 
non-zero values, while all other elements are zero. Using a single-dimensional array (int *data)
to store only the diagonal elements saves memory compared to using a two-dimensional array or a
double pointer to represent the entire matrix. Additionally, accessing and manipulating elements
in a single-dimensional array can be more efficient than using a double pointer, as it requires fewer
memory lookups and indirections.
*/