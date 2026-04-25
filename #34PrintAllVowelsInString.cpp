/*Write a program to read a string then print all vowels in that
string (Vowels are: a, e ,i ,o ,u )*/
#include <iostream>
#include "MyLib.h"
using namespace std ;
void PrintAllVowels (string & text){
    const unsigned int s = text.size();
    for(unsigned int i =0 ;i<s;i++){
        if(mystring::IsVowel(text[i])){
            cout<<text[i]<<" ";
        }
    }


}
int main () {
    string text =inputuser::InputStringFromUser("Please enter your String : ");
    cout<<"Vowels in string are : ";
    PrintAllVowels(text);
    return 0 ;
}