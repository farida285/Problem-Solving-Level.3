/*Write a program to read a string then make a function to
split each word in vector.*/
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
void PrintStringVector (const vector<string> &vsplit){
    for(const string & text:vsplit){
        cout<<text<<endl;
    }
}
int main (){
    string text = InputStringFromUser("Please enter your string : ");
    vector<string> vsplit = SplitString(text," ") ;
    cout<<"Tokens = "<<vsplit.size()<<endl;
    PrintStringVector(vsplit);

    return 0;
}
