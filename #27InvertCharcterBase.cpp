//Write a program to read a character then invert it's case and print it.
#include <iostream>
#include <string>
#include <limits>
using namespace std ;
char InputCharFromUser (const string &massege){
    string input ;
    cout<<massege;
    do{
        cin>>input;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(input.size()>1){
            cout<<"Please enter one charcter : ";
        }
    }while (input.size()>1);
    
    return  input[0] ;
}
char MyToUpper(char letter){
    if(letter>='a'&&letter<='z'){
        letter -= 32;
    }
    return letter;
}
char MyToLower(char letter){
    if(letter>='A'&&letter<='Z'){
        letter += 32;
    }
    return letter;
}
bool MyIsUpper(const char letter){
    return(letter>='A'&&letter<='Z');
}
bool MyIsLower(const char letter){
 return(letter>='a'&&letter<='z');
  
}
char InvertChar (char letter){
    return MyIsUpper(letter)?  MyToLower(letter)  : MyToUpper(letter) ; 
}
int main (){
    char myChar =InputCharFromUser("Please enter your char : ") ;
    cout<<"Char after inverted : \n";
    myChar=InvertChar(myChar);
    cout<<myChar<<endl;
    return 0;
}