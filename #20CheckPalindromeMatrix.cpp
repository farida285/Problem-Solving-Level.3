//Write a program to check if the matrix is palindrome or not.
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
bool CheckPalidromeMatrix(int matrix[row][colmn]){
  for(unsigned short i =0;i<row;i++){
     for(unsigned short j =0;j<(colmn/2);j++){
          if(matrix[i][j]!=matrix[i][colmn-1-j]){
            return 0 ;
          }
        }
   
    }
    return 1 ;
}
int main(){
    int matrix1[row][colmn]={{10,2,10},{40,5,40},{800,1,7}};
    cout<<"Matrix1 :\n";
    Print3X3Matrix(matrix1);
    cout<<endl ;
    (CheckPalidromeMatrix(matrix1))? cout<<"This matrix is palidrome.\n" : cout<<"This matrix is not palidrome.\n";
    cout<<endl ;
    
    int matrix2[row][colmn]={{1,2,1},{4,5,4},{8,1,8}};
    cout<<"Matrix2 :\n";
    Print3X3Matrix(matrix2);
    cout<<endl ;
    (CheckPalidromeMatrix(matrix2))? cout<<"This matrix is palidrome.\n" : cout<<"This matrix is not palidrome.\n";
    return 0 ;
}
