/*Write a program to fill a 3x3 matrix with random numbers,
print it , then print the middle row and middle col.*/
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
void PrintMidRow (int matrix[row][colmn]){
    unsigned short midrow = row/2;
    cout<<"Middle row of matrix : \n";
    for(unsigned int i =0 ;i<colmn;i++){
        printf("%0*d  ",2,matrix[midrow][i]);
    }

}
void PrintMidColmn (int matrix[row][colmn]){
    unsigned short midcol = colmn/2;
    cout<<"Middle col of matrix : \n";
    for(unsigned int i =0 ;i<row;i++){
        printf("%0*d  ",2,matrix[i][midcol]);
    }

}
int main (){
    srand((unsigned)time(NULL));
    int matrix [row][colmn];
    FillRandomMatrix(matrix,1,10);
    cout<<"The following 3x3 Random Matrix : \n";
    PrintMatrix (matrix);
    cout<<endl;  
    PrintMidRow(matrix);
    cout<<endl;
    PrintMidColmn(matrix);
    return 0;
}