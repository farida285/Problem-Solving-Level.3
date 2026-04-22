//Write a program to read bank client data record and convert it to one line:
#include <iostream>
#include <string>
#include "MyLib.h"
using namespace std ;
struct stClient {
    string accountNumber ;
    string  pinCode ;
    string name;
    string phoneNumber ;
    double accountBalance ;
};
stClient ReadNewClient (){
    stClient c1;
    c1.accountNumber=inputuser::GetStringInSize("Enter account number ? ",4,4);
    c1.pinCode=inputuser::GetStringInSize("Enter pinCode ?",4,4);
    c1.name=inputuser::InputStringFromUser("Enter name ?");
    c1.phoneNumber=inputuser::GetStringInSize("Enter phone number ?",11,11);
    c1.accountBalance=inputuser::FloatNumber("Enter account Balance ?");
    return c1 ;
}
string ConvertRecordToLine(const stClient &c1,string separator){
    string s1 ="";
    s1+=c1.accountNumber+separator;
    s1+=c1.pinCode+separator;
    s1+=c1.name+separator;
    s1+=c1.phoneNumber+separator;
    s1+=to_string(c1.accountBalance);
    return s1 ;
}
int main (){
    cout<<"Please enter client data :\n\n";
    stClient c1 =ReadNewClient();
    cout << "\n\nClient Record for Saving is: \n";
    cout<<ConvertRecordToLine(c1,"#//#");
    return 0;
}