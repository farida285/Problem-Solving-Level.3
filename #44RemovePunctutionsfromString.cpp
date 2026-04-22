//Write a program to remove all punctuations from a string.
#include <iostream>
#include <string>
using namespace std ;
bool Ispunctuations (char charcter){
    int c=(int)charcter;
    return((c>=33&&c<=47)||(c>=58&&c<=64)||(c>=91&&c<=96)||(c>=123&&c<=126));
}

string RemoveAllPunctuations (const string &s1){
    string s2="";
    s2.reserve(s1.size());
    unsigned int size =s1.length();
    for(unsigned int i=0;i<size;i++){
        if(!Ispunctuations(s1[i])){
            s2+=s1[i];
        }
    }
    return s2 ;
}
int main (){
    string S1 = "Welcome to Jordan, Jordan is a nice country; it's amazing.";
    cout << "Original String:\n" << S1<<endl<<endl;
    cout << "Pauncuations Removed:\n"<<RemoveAllPunctuations(S1);
    return 0;
}