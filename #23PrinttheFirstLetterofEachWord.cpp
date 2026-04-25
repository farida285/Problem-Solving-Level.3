//Write a program to read a string then print the first letter of each word in that string
#include <string>
#include <iostream>
using namespace std;
string GetStringInSize (const string &message,unsigned short from,unsigned short to){
    string text ;
    unsigned size ;
    cout << message<<endl;
    do{
        getline(cin>>ws,text) ;
        size=text.size() ;
        if(size>to||size<from){
            cout <<"Enter text in range from "<<from<<" to "<<to<<" characters:\n";
        }
    }while(size>to||size<from) ;
    return text ;
}

void FirstLetterofEachWord (const string &text){
    cout<<"First letters of each word :\n";
     bool afterSpace=true;
    for(unsigned int i= 0 ;i<text.size();i++){
        if(text[i] != ' ' && afterSpace){
            cout<<text[i]<<endl;
        }
        (text[i]==' ') ? afterSpace=true : afterSpace=false ;

    }
}
int main (){
string text =GetStringInSize("Enter the text : ",1,500);
 FirstLetterofEachWord(text);
    return 0 ;
}