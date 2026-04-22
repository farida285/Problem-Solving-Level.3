/*Write a program to fill two 3x3 matrix with random numbers
and them, then write a function to sum all numbers in this
matrix and print it.*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include<cstdio>
using namespace std ;
const unsigned int row = 3;
const unsigned int colmn = 3;
int RandomNumber (int from , int to ){
    return (rand()%(to-from+1)+from);
}
void FillRandomMatrix (int matrix[row][colmn],int from , int to){
    for (unsigned int i=0;i<row;i++){
        for(unsigned int j=0;j<colmn;j++){
            matrix[i][j]=RandomNumber(from,to);
        }
    }
}
void PrintMatrix(const int matrix [row][colmn]){
    for (unsigned int i=0;i<row;i++){
        for(unsigned int j=0;j<colmn;j++){
            printf("%0*d  ",2,matrix[i][j]);
        }
        cout<<endl;
    }

}
int SumAllMatrixElements(int matrix[row][colmn]){
    int sum =0 ;
    for(unsigned int i =0 ;i<row;i++){
        for(unsigned int j =0 ;j<colmn;j++){
            sum+=matrix[i][j];
        }
    }
    return sum ;
}

int main (){
    srand((unsigned)time(NULL));
    int matrix [row][colmn];
    FillRandomMatrix(matrix,1,10);
    cout <<"Matrix :\n";
    PrintMatrix(matrix);
    cout <<"Sum of all elements in matrix : "<<SumAllMatrixElements(matrix);
    return 0 ;
}