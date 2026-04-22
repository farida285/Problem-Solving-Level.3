/*Write a program to fill a 3x3 matrix with random numbers ,
then sum each row in separate array and print the results:*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include<iomanip>
using namespace std ;
const unsigned int row =3 ;
const unsigned int colmn=3 ;
int RandomNumber (int from ,int to ){
    return(rand()%(to-from+1)+from);
}
void Fill3x3RandomMatrix (int matrix[row][colmn],int from,int to){
    for(unsigned short i =0;i<row;i++){
         for(unsigned short j =0;j<colmn;j++){
            matrix[i][j]=RandomNumber(from,to);
        }
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
int RowSum (int matrix[row][colmn],int rownumber){
    int sum =0 ;
    for(unsigned short i =0;i<colmn;i++){
        sum+=matrix[rownumber][i];
    }
    return sum ;
}
void CreateMatrixRowSumArray (int arr[row],int matrix[row][colmn]){
    for(unsigned int i=0;i<row;i++){
        arr[i]=RowSum(matrix,i);
    }

}
void printMatrixRowSumArray (const int arr[row]){
for( unsigned short i=0;i<row;i++){
    printf("Row %d sum : %d\n",i+1,arr[i]);
}
  
}

int main ( ){
srand((unsigned)time(NULL));
    int matrix [row][colmn]; 
    int arr[row];
    Fill3x3RandomMatrix(matrix,1,100);
    cout<<"The following is a 3x3 Random Matrix : \n";
    Print3X3Matrix (matrix);
    CreateMatrixRowSumArray (arr,matrix);
    cout<<"The following are the sum of each row : \n";
    printMatrixRowSumArray(arr);


    return 0 ;
}