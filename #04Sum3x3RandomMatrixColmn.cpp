/*Write a program to fill a 3x3 matrix with random numbers,
then print each Col sum:*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>
using namespace std ;
const unsigned int row = 3;
const unsigned int colmn =3;
int RandomNumber (int from , int to){
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
int SumColmn (int matrix[row][colmn],unsigned int colmnNumber){
    int sum = 0;
    for(unsigned int i =0;i<row;i++){
        sum+=matrix[i][colmnNumber];
    }
    return sum ;
}
void PrintSumofColmn (int matrix[row][colmn]){
    for(unsigned int i =0 ;i<colmn;i++){
        printf("Col %d sum : %d\n",i+1,SumColmn(matrix,i));
    }

}

int main (){
    srand((unsigned)time(NULL));
    int matrix [3][3];
    Fill3x3RandomMatrix(matrix,1,100);
    cout<<"The following is a 3x3 Random Matrix : \n";
    Print3X3Matrix (matrix);
    cout<<"The following are the sum of each colmn : \n";
    PrintSumofColmn(matrix);

    return 0 ;
}