//Write a program to read a string then uppercase the first letter of each word in that string
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
string UppercasetheFirstLetter (string text){
   bool afterSpace = true ;
   for(unsigned int i=0;i<text.size();i++){
    if(text[i]!=' '&& afterSpace){
          text[i]=MyToUpper(text[i]);
    }
    (text[i]==' ')? afterSpace=true : afterSpace=false ;
   }
   return text;
}
int main (){
    string myText =UppercasetheFirstLetter(InputStringFromUser("Please enter your string : ")) ;
    cout<<"String after conversition : \n";;
    cout<<myText<<endl;

    return 0;
}