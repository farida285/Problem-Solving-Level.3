//Write a program to read a string then count small/capital letters in that string
#include "MyLib.h"
#include <iostream>
using namespace std ;
enum enWhatCount {smallLetters=0,capitalLetters,allChar};

unsigned int CountInString(string & myText,enWhatCount whatCount=enWhatCount::allChar){
    if(whatCount==enWhatCount::allChar){
        return (myText.size());
    }
    unsigned int count =0 ;
    for(unsigned int i=0;i<myText.size();i++){
        if(mystring::MyIsUpper(myText[i])&&whatCount==enWhatCount::capitalLetters){
            count++ ;
        }else if(mystring::MyIsLower(myText[i])&&whatCount==enWhatCount::smallLetters){
            count++ ;
        }
    }
    return count ;
}
int main (){
    string myText=inputuser::InputStringFromUser("Please enter your String : ");
    cout<<"String length = "<<CountInString(myText)<<endl;
    cout<<"Capital letters count = "<<CountInString(myText,enWhatCount::capitalLetters)<<endl;
    cout<<"Small letters count = "<<CountInString(myText,enWhatCount::smallLetters)<<endl;
    return 0;
}