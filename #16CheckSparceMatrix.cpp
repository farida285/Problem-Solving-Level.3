//Write a program to check if the matrix is sparce or not.
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std ;
const unsigned int row =3 ;
const unsigned int colmn =3 ;
unsigned int CountNumberinMatrix (int matrix [row][colmn],int number){
   unsigned int count =0;
        for(unsigned int i =0;i<row;i++){
            for(unsigned int j =0 ;j<colmn;j++){
                if(matrix[i][j]==number){
                    count++ ;
                }
            }
        }
    return count ;
}
void Print3X3Matrix (int matrix[row][colmn]){
     for(unsigned short i =0;i<row;i++){
         for(unsigned short j =0;j<colmn;j++){
            cout<<setw(3)<<matrix[i][j]<<"  ";
           }
           cout<<endl;
     }
}
bool IsSparceMatrix (int matrix [row][colmn]){
 return ((CountNumberinMatrix(matrix,0)>((row*colmn)/2)));
}
int main (){
    int matrix1 [row][colmn]={{10,3,0},{3,10,0},{11,5,10}};
    int matrix2 [row][colmn]={{10,3,0},{0,10,0},{10,0,0}};
    cout<<"Matrix1 : \n";
    Print3X3Matrix(matrix1);
    cout<<endl;
    (IsSparceMatrix(matrix1))? cout<<"This matrix is sparce.\n" : cout<<"This matrix is not sparce.\n" ;
    cout<<endl;
    cout<<"Matrix2 : \n";   
    Print3X3Matrix(matrix2);
    cout<<endl;
    (IsSparceMatrix(matrix2))? cout<<"This matrix is sparce.\n" : cout<<"This matrix is not sparce.\n" ;


    
    return 0;
}