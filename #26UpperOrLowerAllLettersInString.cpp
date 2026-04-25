//Write a program to read a string then upper all letters , then lower all letters , and print them.
#include <iostream>
#include <string>
using namespace std ;
string InputStringFromUser (const string &message){
    string input ;
    cout<<message;
    getline(cin,input);
    return input ;
}
char MyToUpper(char letter){
    if((int)letter>=97&&(int)letter<=122){
        letter=char(((int)letter)-32);
    }
    return letter;
}
char MyToLower(char letter){
    if((int)letter>=65&&(int)letter<=90){
        letter=char(((int)letter)+32);
    }
    return letter;
}
string UpperAllString (string text){
   for(unsigned int i=0;i<text.size();i++){
    if(text[i]!=' '){
          text[i]=MyToUpper(text[i]);
    }
   }
   return text;
}
string LowerAllString (string text){
   for(unsigned int i=0;i<text.size();i++){
    if(text[i]!=' '){
          text[i]=MyToLower(text[i]);
    }
   }
   return text;
}
int main (){
    string myText =InputStringFromUser("Please enter your string : ") ;
    cout<<"String after Upper : \n";;
    myText=UpperAllString(myText);
    cout<<myText<<endl;
    cout<<"String after lower : \n";;
    myText=LowerAllString(myText);
    cout<<myText<<endl;
    return 0;
}