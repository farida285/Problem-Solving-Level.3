/*Write a program to read a string and read a character then
count the character in that string (Match Case or Not)*/
#include "MyLib.h"
#include <iostream>
using namespace std ;
char InvertChar (char letter){
    return (mystring::MyIsUpper(letter))?  mystring::MyToLower(letter)  : mystring::MyToUpper(letter) ; 

}
unsigned int CountCharInString (string & myText,char charcter,bool matchCase=true){
    
    unsigned int count =0 ;
    if(matchCase){
        for(unsigned int i=0;i<myText.size();i++){
            if(myText[i]==charcter){
            count++ ;
             }
        }
    }else {
     char inverted=InvertChar(charcter) ;
     for(unsigned int i=0;i<myText.size();i++){
         if(myText[i]==charcter||myText[i]==inverted){
            count++ ;
            }           
        } 
    }  
     
    return count ;
}

int main (){
    string myText=inputuser::InputStringFromUser("Please enter your String : ");
    char searchChar=inputuser::InputCharFromUser("Please enter the character : ");
    cout<<"Letter '"<<searchChar<<"' Count = "<<CountCharInString(myText,searchChar)<<endl;
    cout<<"Letter '"<<searchChar<<"' or '"<<mystring::InvertChar(searchChar)<<"' Count = "<<CountCharInString(myText,searchChar,false);
    return 0 ;
}