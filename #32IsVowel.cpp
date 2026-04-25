//Write a program to read a character the check if it is a vowel or not (Vowels are: a, e ,i ,o ,u )
#include <iostream>
#include "MyLib.h"
#include <vector>
using namespace std ;
bool IsVowel(const char &charcter){
 char c= mystring::MyToLower(charcter);
    return(c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int main (){
    char charcter = inputuser::InputCharFromUser("Please enter the charcter : ");
    (IsVowel(charcter))? cout<<"Yes, It is vowel ." : cout<<"No, It is not vowel .";

    return 0;
}