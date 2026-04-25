/*Write a program to read a string then count each word in
that string.*/
#include <iostream>
#include <string>
using namespace std  ;
string InputStringFromUser (const string &massege){
    string input ;
    cout<<massege<<endl;
    getline(cin,input);
    return input ;
}
unsigned short CountEachWordInString(string s1){
	string word = "";
    string space = " ";
    unsigned short count = 0;
   int position =0;
    while((position=s1.find(space))!=string::npos){
        word=s1.substr(0,position);
        if(word!=""){
            count++ ;
        }
        s1.erase(0,position+space.length());
    }
    if(s1!=""){
        count++ ;
    }
    return count ;
  
}
int main(){
    string text =InputStringFromUser("Please enter your string : ");
    cout << "The number of words in your string is : " << CountEachWordInString(text);
    return 0;
}