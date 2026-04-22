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

int main (){
     vector <string> vword ={"Farida","Mahmoud","Abdelnaby"};
     cout<<"Vector after join : \n";
     cout<<Join(vword,"--");
    return 0;
}