//Write a program to replace word in string.
#include <iostream>
#include <string>
using namespace std ;
string ReplaceWordInString1 (string s1,string origWord,string newWord, char extraSeparator=' '){
   
     size_t  position =0;

    while ((position=s1.find(origWord,position))!=string::npos)
    { 
        bool leftOK=(position==0||(s1[position-1]==' '||s1[position-1]==extraSeparator));
        bool rightOk= ( position+origWord.size()==s1.size() || (s1[position+origWord.size()]==' ' || s1[position+origWord.size()]==extraSeparator)) ;
        if(leftOK&&rightOk){
        s1= s1.replace(position,origWord.size(),newWord);
        position +=newWord.size();
        }else{
            position+=origWord.size();
        }
    
    }
    return s1;

}
string ReplaceWordInString (string s1,string origWord,string newWord,char extraSeparator=' '){
   
    size_t  position = 0;

    while ((position=s1.find(origWord,position))!=string::npos)
    { 
        bool leftOK=(position==0||(s1[position-1]==' '||s1[position-1]==extraSeparator));
        bool rightOk= ( position+origWord.size()==s1.size() || (s1[position+origWord.size()]==' ' || s1[position+origWord.size()]==extraSeparator)) ;
        if(leftOK&&rightOk){
        s1.erase(position,origWord.size());
        s1.insert(position,newWord);
        position+=newWord.size();
        }else{
            position+=origWord.size();
        }
       
    }
    return s1;

}
int main(){
    string s1 = "Welcome to Jordan , Jordan is a nice country";
    cout << "Origial String:\n" << s1<<endl<<endl;
    cout << "String After Replace:\n"<<ReplaceWordInString (s1,"Jordan","USA")<<endl;
 
    return 0;
}