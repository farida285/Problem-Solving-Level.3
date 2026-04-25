//Write a program to read string and reverse its words.
#include <iostream>
#include <string>
#include "MyLib.h"
#include  <vector>
using namespace std ;
vector<string> SplitString (string s1,string separator){
    vector<string> vsplit ;
    string word = "" ;
    size_t position = 0;

    while ((position=s1.find(separator))!=s1.npos)
    {
        word=s1.substr(0,position);
        if(word!=""){
            vsplit.push_back(word);
        }
        s1.erase(0,position+separator.length());
    }
    if(s1!=""){
         vsplit.push_back(s1);
    }
    return vsplit ;
    
}
string ReverseWordsInString (string &s1){
    vector<string> vsplit =SplitString(s1," ");
    string words ="";
     for (int i = (int)vsplit.size()-1 ; i >=0 ;i--) {
        words += vsplit[i];
        if (i != 0)
         words += " ";
      }
    return(words);
}
string ReverseWordsInString1 (string &s1){
    vector<string> vsplit =SplitString(s1," ");
    string words ="";
    vector<string>::iterator iter =vsplit.end();
    while(iter!=vsplit.begin()){
        iter--;
        words+=*iter;
        if(iter!=vsplit.begin()){
            words+=" ";
        }
    }
    return(words);
}
int main (){
    string text =inputuser::InputStringFromUser("Please enter your String : ");
    cout<<"String after reversed words :"<<endl;
    cout<<ReverseWordsInString(text)<<endl;
    cout<<ReverseWordsInString1(text)<<endl;
    return 0;
}