#include <iostream>
#include <iomanip>
using namespace std ;
const unsigned short row =3;
const unsigned short colmn = 3;
void Print3X3Matrix (int matrix[row][colmn]){
     for(unsigned short i =0;i<row;i++){
         for(unsigned short j =0;j<colmn;j++){
            cout<<setw(3)<<matrix[i][j]<<"  ";
           }
           cout<<endl;
     }
}
int MaxNumberInMatrix(int matrix[row][colmn]){
    int maxNumber =matrix[0][0] ;
    for(unsigned short i=0;i<row;i++){
        for(unsigned short j =0;j<colmn;j++){
            if(matrix[i][j]>maxNumber){
                maxNumber=matrix[i][j];
            }
        }
    }
    return maxNumber;
}
int MinNumberInMatrix(int matrix[row][colmn]){
    int minNumber =matrix[0][0] ;
    for(unsigned short i=0;i<row;i++){
        for(unsigned short j =0;j<colmn;j++){
            if(matrix[i][j]<minNumber){
                minNumber=matrix[i][j];
            }
        }
    }
    return minNumber;
}
int main(){
    int matrix[row][colmn]={{10,2,3},{40,5,6},{800,1,2}};
    cout<<"Matrix :\n";
    Print3X3Matrix(matrix);
    cout<<endl ;
    cout<<"Max Number in a Matrix = "<<MaxNumberInMatrix(matrix)<<endl;
    cout<<"Min Number in a Matrix = "<<MinNumberInMatrix(matrix)<<endl;
    return 0 ;
}
