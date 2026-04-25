/*Write a program to read a string then print each word in that
string.*/
#include <iostream>
#include "MyLib.h"
#include <string>
using namespace std  ;
void PrintEachWordInString1(string &s){
    bool afterSpace = true;
    for(unsigned int i=0;i<s.size();i++ ){
        if(s[i]!=' '){
            cout<<s[i];
            afterSpace= false ;
            if(i==s.size()-1){
                cout<<endl;
            }
        }
        else if(s[i]==' '&&afterSpace==false){
            cout<<endl;
            afterSpace=true ;
        }
    }
    
}
void PrintEachWordInString2(string s1){
    string sword ;
     int position=0 ;
    string space =" ";
    while((position=s1.find(space))!=s1.npos){
        sword=s1.substr(0,position);
        if(sword!=""){
            cout<<sword<<endl;
        }
        s1.erase(0,position+space.size());
    }
    if(s1!=""){
        cout<<s1<<endl;
    }
}
int main(){
    string text =inputuser::InputStringFromUser("Please enter your string : ");
    PrintEachWordInString1(text) ;
     text =inputuser::InputStringFromUser("Please enter your string : ");
    PrintEachWordInString2(text) ;
    return 0;
}