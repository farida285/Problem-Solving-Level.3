//Write a program to read bank client data record and convert it to one line:
#include <iostream>
#include <string>
#include <vector>
#include "D:\Level2 C++\Level2 C++\#02MyLib.h"
using namespace std ;
struct stClient {
    string accountNumber ;
    string  pinCode ;
    string name;
    string phoneNumber ;
    double accountBalance ;
};
stClient ConvertLineToRecord(const string &s1,string separator){
    stClient c1 ;
    vector<string> vstring =mystring::SplitString(s1,"#//#");
    c1.accountNumber=vstring[0];
    c1.pinCode=vstring[1];
    c1.name=vstring[2];
    c1.phoneNumber=vstring[3];
    c1.accountBalance=stod(vstring[4]);
    return c1 ;
}
void PrintClientRecord (const stClient & c1){
    cout << "Account Number  : "<<c1.accountNumber;
    cout << "\nPinCode         : "<<c1.pinCode;
    cout << "\nName            : "<<c1.name;
    cout << "\nPhone number    : "<<c1.phoneNumber;
    cout << "\nAccount Balance : "<<to_string(c1.accountBalance);
}
int main (){
   
    string s1 ="A444#//#2002#//#Farida Mahmoud#//#01273360778#//#400000.000000";
    cout<<"Line Record is :\n"<<s1<<endl;
    stClient c1=ConvertLineToRecord(s1,"#//#");
    cout << "\nThe Following is the extracted client record :\n";
    PrintClientRecord(c1);
    return 0;
}