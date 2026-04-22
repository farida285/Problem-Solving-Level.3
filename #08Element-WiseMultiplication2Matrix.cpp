/*Write a program to fill two 3x3 matrix with random numbers
and them, then multiply (Element-wise multiplication) them into a 3rd matrix and print it.*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>
using namespace std ;
const unsigned int row =3 ;
const unsigned int colmn=3 ;
int RandomNumber (int from ,int to ){
    return(rand()%(to-from+1)+from);
}
void FillRandomMatrix (int matrix[row][colmn],int from,int to){
    for(unsigned short i =0;i<row;i++){
         for(unsigned short j =0;j<colmn;j++){
            matrix[i][j]=RandomNumber(from,to);
        }
    }

}
void PrintMatrix (int matrix[row][colmn]){
     for(unsigned short i =0;i<row;i++){
         for(unsigned short j =0;j<colmn;j++){
            printf("%0*d   ",2,matrix[i][j]);
           }
           cout<<endl;
     }
}
void CreateWiseMultiplymatrix (int matrix1 [row][colmn],
    int matrix2 [row][colmn],
    int wiseMultiplymatrix [row][colmn])
    {
            for(unsigned int i=0;i<row;i++){
                for(unsigned int j=0;j<colmn;j++){
                    wiseMultiplymatrix[i][j]=matrix1[i][j]*matrix2[i][j];
                }
            }

    }
int main ( ){
    srand((unsigned)time(NULL));
    int matrix1 [row][colmn]; 
    int matrix2 [row][colmn];
    int wiseMultiplymatrix [row][colmn];

    FillRandomMatrix(matrix1,1,10);
    cout<<"The following 3x3 Random Matrix : \n";
    PrintMatrix (matrix1);
    cout<<endl;
    FillRandomMatrix(matrix2,1,10);
    cout<<"The following 3x3 Random Matrix : \n";
    PrintMatrix (matrix2);
    cout<<endl;
    CreateWiseMultiplymatrix(matrix1,matrix2,wiseMultiplymatrix);
    cout<<"The following 3x3 Element-wise multiplication Matrix : \n";
    PrintMatrix(wiseMultiplymatrix);
    cout<<endl;

    return 0 ;
}