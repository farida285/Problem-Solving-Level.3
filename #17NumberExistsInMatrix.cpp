//Write a program to check if a given number exists in matrix or not.
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std ;
const unsigned int row =3 ;
const unsigned int colmn =3 ;
int GetNumberfromUser (string message){
    cout<<message<<endl;
    int number ;
    while(!(cin>>number)){
         cout<<"Erorr!!\nPlease enter the number :\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
       
    }
    return number;
}

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

void Print3X3Matrix (int matrix[row][colmn]){
     for(unsigned short i =0;i<row;i++){
         for(unsigned short j =0;j<colmn;j++){
            cout<<setw(3)<<matrix[i][j]<<"  ";
           }
           cout<<endl;
     }
}
int main (){
    int matrix [row][colmn]={{10,3,0},{3,10,0},{11,5,10}};
    Print3X3Matrix(matrix);
    cout<<endl;
    (IsExistInMatrix(matrix,GetNumberfromUser("Enter the number to count in matrix ?")))? cout<<"Yes, it's there.\n" : cout<<"No, it's not there.\n" ; 
    
    return 0;
}