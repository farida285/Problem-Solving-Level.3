/*Write a program to fill a 3x3 matrix with ordered numbers
and print it, then transpose matrix and print it.*/
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std ;
const unsigned int row = 3;
const unsigned int colmn =3;
void Fillorderedmatrix (int matrix [row][colmn]){
    unsigned int counter =0 ;
    for(unsigned int i =0;i<row;i++){
        for(unsigned int j =0;j<colmn;j++){
            counter ++;
            matrix[i][j]=counter ;
        }
    }
}
void CreateTransposeMatrix( int matrix[row][colmn],int transposeMatrix[colmn][row]){
    for(unsigned int j = 0;j<colmn;j++){
        for(unsigned int i = 0;i<row;i++){
            transposeMatrix[j][i]=matrix[i][j];
        }
    }
}
void PrintMatrix (int matrix[row][colmn]){
     for(unsigned short i =0;i<row;i++){
         for(unsigned short j =0;j<colmn;j++){
            cout<<setw(2)<<matrix[i][j]<<"  ";
           }
           cout<<endl;
     }
}
void PrintTransposeMatrix(int matrix[row][colmn]){
    for(unsigned int i=0; i<colmn;i++){
        for(unsigned int j =0 ;j<row ;j++){
            cout<<setw(2)<<matrix[j][i]<<"  ";
        }
        cout<<endl;
    }
}
int main (){
 int matrix[row][colmn];
 int transposeMatrix[colmn][row];
 Fillorderedmatrix(matrix);
 cout<<"The following is a 3x3 Random Matrix : \n";
 PrintMatrix(matrix);
 cout<<endl;
 cout<<"The following is a transpose Matrix by only print : \n";
 PrintTransposeMatrix(matrix);
 cout<<endl;
 CreateTransposeMatrix(matrix,transposeMatrix);
 cout<<"The following is a transpose Matrix by function : \n";
 PrintMatrix(transposeMatrix);
 

    return 0; 
}