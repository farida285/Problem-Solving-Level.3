//Write a program to read a string then invert all its letter's case and print it.
#include <iostream>
#include <string>
#include <limits>
using namespace std ;
string InputStringFromUser (const string &message){
    string input ;
    cout<<message;
    getline(cin,input);
    return input ;
}
char MyToUpper(char letter){
    if(letter>='a'&&letter<='z'){
        letter -= 32;
    }
    return letter;
}
char MyToLower(char letter){
    if(letter>='A'&&letter<='Z'){
        letter += 32;
    }
    return letter;
}
bool MyIsUpper(const char letter){
    return(letter>='A'&&letter<='Z');
}

char InvertChar (char letter){
    return MyIsUpper(letter)?  MyToLower(letter)  : MyToUpper(letter) ; 
}
string InvertString (string myText){
    for(unsigned int i=0;i<myText.size();i++){
        myText[i]=InvertChar(myText[i]);
    }
    return myText;
}
int main (){
    string myText =InputStringFromUser("Please enter your String : ") ;
    cout<<"String after inverted : \n";
    myText=InvertString(myText);
    cout<<myText<<endl;
    return 0;
}