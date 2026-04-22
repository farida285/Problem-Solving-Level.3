//Write a program to read a string then Trim Left, Right , All.
#include <iostream>
#include <string>
#include <vector>
using namespace std ;
string InputStringFromUser (const string &massege){
    string input ;
    cout<<massege<<endl;
    getline(cin,input);
    return input ;
}
string  TrimLeft (const string &s1){
 unsigned int size =s1.length();
    for(unsigned int i =0 ;i<size;i++){
        if(s1[i] != ' '){
            return (s1.substr(i,size-i));
        }
    }
    return "";   
}

string  TrimRight (const string &s1){
 unsigned int size =s1.length();
    for(unsigned int i =size-1 ;i>=0;i--){
        if(s1[i] != ' '){
            return (s1.substr(0,i+1));
        }
    }
    return "";   
    
}
string  Trim (const string &s1){

    return (TrimLeft(TrimRight(s1)));   
}
int main (){
    string text = InputStringFromUser("Please enter your string : ");
    cout<<"Trim Left  = "<<TrimLeft(text)<<endl;
    cout<<"Trim Right = "<<TrimRight(text)<<endl;
    cout<<"Trim       = "<<Trim(text)<<endl;


    return 0;
}