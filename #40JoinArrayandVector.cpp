//Write a program to join array of strings into a one string with separators
//Write a program to join vector of strings into a one string with separators
#include <iostream>
#include <string>
#include  <vector>
using namespace std ;
string Join (const vector <string> &vword , string separator ){
    string words ="";
     for (size_t i = 0; i < vword.size(); i++) {
        words += vword[i];
        if (i != vword.size() - 1)
            words += separator;
    }
    return(words);
}
string Join (const string  arr [] ,unsigned short size, string separator ){
    string words ="";
    for(unsigned short i=0;i<size;i++){
        words+=arr[i];
        if(i!=size-1){
            words+=separator;
        }
    }
    return(words);
}
int main (){
     vector <string> vword ={"Farida","Mahmoud","Abdelnaby"};
     string arr[]={"Farida","Mahmoud","Abdelnaby"};
     cout<<"Vector after join : \n";
     cout<<Join(vword,"--")<<endl;
     cout<<"Array after join : \n";
     cout<<Join(arr,3,"--")<<endl;
    return 0;
}