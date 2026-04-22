//Write a program to read a string and read a character then count the character in that string
#include "MyLib.h"
#include <iostream>
using namespace std ;

unsigned int CountCharInString(string & myText,char charcter){
    
    unsigned int count =0 ;
    for(unsigned int i=0;i<myText.size();i++){
        if(myText[i]==charcter){
            count++ ;
        }     
    }
    return count ;
}
int main (){
    string myText=inputuser::InputStringFromUser("Please enter your String : ");
    char searchChar=inputuser::InputCharFromUser("Please enter the character : ");
    cout<<"Letter '"<<searchChar<<"' Count = "<<CountCharInString(myText,searchChar);
    return 0 ;
}