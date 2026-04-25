//Write a program to fill a 3x3 matrix with ordered numbers.
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
void PrintMatrix (int matrix[row][colmn]){
     for(unsigned short i =0;i<row;i++){
         for(unsigned short j =0;j<colmn;j++){
            cout<<setw(2)<<matrix[i][j]<<"  ";
           }
           cout<<endl;
     }
}
int main (){
 int matrix[row][colmn];
 Fillorderedmatrix(matrix);
 cout<<"The following is a 3x3 Random Matrix : \n";
 PrintMatrix(matrix);
    return 0; 
}