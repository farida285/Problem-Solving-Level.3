//Write a program to check if the matrix is identity or not.
#include <iostream>
#include <iomanip>
using namespace std ;
const unsigned int row =3 ;
const unsigned int colmn =3 ;
bool CheckScalartyMatrix (int matrix [row][colmn]){
    if(row!=colmn){
        return 0;
    }else
    {
        for(unsigned int i =0;i<row;i++){
        
            for(unsigned int j =0 ;j<colmn;j++){
                if(i==j&&matrix[i][j]!=1){
                              return 0 ;
                }else if(i!=j&&matrix[i][j]!=0){
                  return 0 ;   
                }
            }
        }
        return 1 ;
    }
}
void Print3X3Matrix (int matrix[row][colmn]){
     for(unsigned short i =0;i<row;i++){
         for(unsigned short j =0;j<colmn;j++){
            cout<<setw(3)<<matrix[i][j]<<"  ";
           }
           cout<<endl;
     }
}
int main (){
    int matrix1 [row][colmn]={{1,0,0},{0,1,0},{0,0,1}};
    int matrix2 [row][colmn]={{1,1,0},{0,1,0},{0,0,1}}; 
    int matrix3 [row][colmn]={{1,0,5},{0,1,6},{0,0,1}};
    Print3X3Matrix(matrix1);
    cout<<endl;
    (CheckScalartyMatrix(matrix1))? cout<<"Yes : Matrix is identity.\n" : cout<<"No : Matrix is not identity.\n";
    cout<<endl;
    Print3X3Matrix(matrix2);
    cout<<endl;
    (CheckScalartyMatrix(matrix2))? cout<<"Yes : Matrix is identity.\n" : cout<<"No : Matrix is not identity.\n";
    cout<<endl;        
    Print3X3Matrix(matrix3);
    cout<<endl;
    (CheckScalartyMatrix(matrix3))? cout<<"Yes : Matrix is identity.\n" : cout<<"No : Matrix is not identity.\n";
    cout<<endl;

    return 0;
}