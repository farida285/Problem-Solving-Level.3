#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std ;

namespace mystring {
bool MyIsUpper(const char letter){
    return(letter>='A'&&letter<='Z');
}
bool MyIsLower(const char letter){
 return(letter>='a'&&letter<='z');
  
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
char InvertChar (char letter){
    return (mystring::MyIsUpper(letter))?  mystring::MyToLower(letter)  : mystring::MyToUpper(letter) ; 

}
string UpperAllString (string text){
   for(unsigned int i=0;i<text.size();i++){
    if(text[i]!=' '){
          text[i]=mystring::MyToUpper(text[i]);
    }
   }
   return text;
}
string LowerAllString (string text){
   for(unsigned int i=0;i<text.size();i++){
    if(text[i]!=' '){
          text[i]=mystring::MyToLower(text[i]);
    }
   }
   return text;
}
enum enWhatCount {smallLetters=0,capitalLetters,allChar};
unsigned int CountInString(string & myText,mystring::enWhatCount whatCount=enWhatCount::allChar){
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
unsigned int MyStringLength(const string &text) {
    unsigned int count = 0;
    while (text[count] != '\0') {
        count++;
    }
    return count;
}
bool IsVowel(const char &charcter){
 char c= mystring::MyToLower(charcter);
    return(c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
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
string  TrimLeft (const string &s1){
 unsigned int size =s1.length();
    for(unsigned int i =0 ;i<size;i++){
        if(s1[i] != ' '){
            return (s1.substr(i,size-i));
        }
    }
    return "";   
}
string  TrimRight (const string &s1){
 unsigned int size =s1.length();
    for(unsigned int i =size-1 ;i>=0;i--){
        if(s1[i] != ' '){
            return (s1.substr(0,i+1));
        }
    }
    return "";   
    
}
string  Trim (const string &s1){

    return (TrimLeft(TrimRight(s1)));   
}
string Join (const vector <string> &vword , string separator ){
    string words ="";
     for (size_t i = 0; i < vword.size(); i++) {
        words += vword[i];
        if (i != vword.size() - 1)
            words += separator;
    }
    return(words);
}

}
namespace inputuser {
int IntegerNumber(const string &message){
    cout<<message<<endl ;
    int number ;
    while (!(cin>>number))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid input , Please enter integer number:\n"; 
    }
    return number ;
}
unsigned int PositiveIntegerNumber(const string &message){
    cout<<message<<endl ;
    int number;
do{
    if(!(cin>>number)){
        cin.clear() ;
        cin.ignore(numeric_limits<streamsize>::max(),'\n') ;
        cout<<"Invalid input , Please enter integer number:\n"; 

    }else if(number<=0){
        cout<<"Please enter positive number:\n";
    }else{
        return (unsigned) number ;

    }
}while(true);
    
}
unsigned short PositiveShortNumberInRange (const string &message ,unsigned short from ,unsigned short to ){
    int number ;
    cout<<message<<endl ;
    do{
        if (!(cin >> number))  
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
        }else if(number<from||number>to){
            cout<<"Unavailable numbers!!\n" ;
            cout<<"Enter number in range from "<<from<<" to "<<to<<".\n";
        }else{
             return (unsigned short)number ;
        }
    }while(true);
   
}
float FloatNumber(const string &message){
    float number ;
    cout<<message<<endl ;
    while(!(cin>>number)){
        cin.clear() ;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a number.\n";
    }

    return number ;
}
bool YesOrNo (const string &message){
    string Answer ;
    cout<<message<<endl;
    do{
        cin>>Answer ;
        Answer=mystring::LowerAllString(Answer);

        if( !(Answer=="yes"||Answer=="y"|| Answer=="no"||Answer=="n"))
            {
            cout<<"Please Enter yes or no : \n" ;
            }
    }while(!(Answer=="yes"||Answer=="y"|| Answer=="no"||Answer=="n"));
    if(Answer=="yes"||Answer=="y"){
        return 1 ;
    }else{
        return 0 ;
    }
    

}
string GetStringInSize (const string &message,unsigned short from,unsigned short to){
    string text ;
    unsigned size ;
    cout << message<<endl;
    do{
        getline(cin>>ws,text) ;
        size=text.size() ;
        if(size>to||size<from){
            cout <<"Enter text in range "<<to<<" characters:\n";
        }
    }while(size>to||size<from) ;
    return text ;
}
string InputStringFromUser (const string &message){
    string input ;
    cout<<message<<endl;
    getline(cin>>ws,input);
    return input ;
}
char InputCharFromUser (const string &message){
    string input ;
    cout<<message<<endl;
    do{
        cin>>input;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(input.size()>1){
            cout<<"Please enter one charcter : ";
        }
    }while (input.size()>1);
    
    return  input[0] ;
}
} ;

