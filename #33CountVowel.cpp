//Write a program to read a string then count all vowels in that string (Vowels are: a, e ,i ,o ,u )
#include <iostream>
#include "MyLib.h"
using namespace std ;
unsigned int CountVowel (string & text){
    unsigned int s = text.size();
    unsigned int count =0;
    for(unsigned int i =0 ;i<s;i++){
        if(mystring::IsVowel(text[i])){
            count++;
        }
    }
    return count ;

}
int main () {
    string text =inputuser::InputStringFromUser("Please enter your String : ");
    cout<<"Number of vowels is : "<<CountVowel(text);
    return 0 ;
}