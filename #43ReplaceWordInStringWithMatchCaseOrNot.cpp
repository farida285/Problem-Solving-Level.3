//Write a program to replace word in string with match case or not using costum function .
#include <iostream>
#include <string>
#include "MyLib.h"
using namespace std ;
string ReplaceWordInString1 (string s1,string origWord,string newWord,bool matchCase=true,char extraSeparator=' '){
   
    size_t  position = 0;
    string smallS1="";
    if(matchCase==false){
        origWord=mystring::LowerAllString(origWord);
        smallS1= mystring::LowerAllString(s1);
    }
    while (( position = (matchCase)? s1.find(origWord,position) : smallS1.find(origWord,position))!=string::npos)
    { 
        bool leftOK=(position==0||(s1[position-1]==' '||s1[position-1]==extraSeparator));
        bool rightOk= ( position+origWord.size()==s1.size() || (s1[position+origWord.size()]==' ' || s1[position+origWord.size()]==extraSeparator)) ;
        if(leftOK&&rightOk){
        s1.erase(position,origWord.size());
        s1.insert(position,newWord);
        if(matchCase==false){
         smallS1.erase(position,origWord.size());
         smallS1.insert(position,newWord);
        }
        position+=newWord.size();
        }else{
            position+=origWord.size();
        }
       
    }
    return s1;

}
string ReplaceWordInString2(string s1,string origWord,string newWord,bool matchCase=true,string separator=" "){
   vector<string> vwords =mystring::SplitString(s1,separator);
   for(string &word:vwords){
    if((matchCase)? word==origWord : mystring::LowerAllString(word)==mystring::LowerAllString(origWord)){
        word=newWord;
    }
   }
   return mystring::Join(vwords,separator) ;
}
int main(){
    string s1 = "Welcome to Jordan , jordan is a nice country";
    cout << "Origial String:\n" << s1<<endl<<endl;

    cout << "Method1 : String After Replace with match case:\n"<<ReplaceWordInString1(s1,"jordan","USA",1)<<endl<<endl;
    cout << "Method1 : String After Replace without match case:\n"<<ReplaceWordInString1 (s1,"jordan","USA",0)<<endl<<endl;

    cout << "Method2 : String After Replace with match case:\n"<<ReplaceWordInString2(s1,"jordan","USA",1)<<endl<<endl;
    cout << "Method2 : String After Replace without match case:\n"<<ReplaceWordInString2 (s1,"jordan","USA",0)<<endl<<endl;
 
    return 0;
}