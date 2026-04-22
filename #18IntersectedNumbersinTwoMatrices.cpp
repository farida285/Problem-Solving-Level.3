//Write a program to print the intersected numbers in two given matrices.
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std ;
const unsigned int row =3 ;
const unsigned int colmn =3 ;
bool IsExistInMatrix (int matrix [row][colmn],int number){
     for(unsigned int i =0;i<row;i++){
         for(unsigned int j =0 ;j<colmn;j++){
            if(matrix[i][j]==number){
                    return 1 ;
             }
         }
     }
    return 0 ;
}
vector <int> IntersectedVector (int matrix1 [row][colmn],int matrix2 [row][colmn]){
  vector <int> intersected ;
      for(unsigned short i =0;i<row;i++){
        for(unsigned short j =0 ;j<colmn;j++){
            if(IsExistInMatrix(matrix2,matrix1[i][j])){
                if(find(intersected.begin(),intersected.end(),matrix1[i][j])==intersected.end()){
                    intersected.push_back(matrix1[i][j]) ;
                }
            }
        }
    }
 return intersected ;
}
void PrintIntersectedNumbers(int matrix1 [row][colmn],int matrix2 [row][colmn]){
for(const int & number : IntersectedVector(matrix1,matrix2)){
 cout<<number<<"  ";
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
int main (){
    int matrix1 [row][colmn]={{10,3,0},{3,10,0},{11,5,10}};
    int matrix2 [row][colmn]={{10,5,0},{7,10,0},{11,12,10}}; 
    cout<<"Matrix1 : \n";
    Print3X3Matrix(matrix1);
    cout<<endl;
    cout<<"Matrix2 : \n";
    Print3X3Matrix(matrix2);
    cout<<endl;
    cout<<"Intersected numbers are :\n";
    PrintIntersectedNumbers(matrix1,matrix2);
    return 0;
}