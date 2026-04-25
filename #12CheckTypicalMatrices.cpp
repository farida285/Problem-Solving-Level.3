/*Write a program to compare two matrices and check if they
are typical or not.*/
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
bool CheckMatricesTypicality (int matrix1 [row][colmn],int matrix2 [row][colmn]){
    for(unsigned int i =0 ;i<row;i++){
        for(unsigned int j =0 ;j<colmn;j++){
            if(matrix1[i][j]!=matrix2[i][j]){
                return 0;
            };
        }
    }
    return 1;
   
}

int main (){
    srand((unsigned)time(NULL));
    int matrix1 [row][colmn];
    int matrix2 [row][colmn];    
    FillRandomMatrix(matrix1,1,10);
    cout <<"Matrix1 :\n";
    PrintMatrix(matrix1);
    cout<<endl;
    FillRandomMatrix(matrix2,1,10);
    cout <<"Matrix2 :\n";
    PrintMatrix(matrix2);
    cout<<endl;
    CheckMatricesTypicality(matrix1,matrix2)? cout<<"Yes : matrices are typical.\n":cout<<"No : matrices are not typical.\n";
    return 0 ;
}