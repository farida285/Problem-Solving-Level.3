//Write a program to ask you to enter clients and save them to file:
#include <iostream>
#include <string>
#include "MyLib.h"
#include <vector>
#include <fstream>
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
string ConvertRecordToLine(const stClient &c1,string separator="#//#"){
    string s1 ="";
    s1+=c1.accountNumber+separator;
    s1+=c1.pinCode+separator;
    s1+=c1.name+separator;
    s1+=c1.phoneNumber+separator;
    s1+=to_string(c1.accountBalance);
    return s1 ;
}
void SaveLineInFile (string fileName,string line){
    fstream myfile;
    myfile.open(fileName,ios::out|ios::app);
    if(myfile.is_open()){
        myfile<<line<<endl;
        myfile.close();
    }
    
}
void AddOneClient(string fileName){
    stClient client ;
       client=ReadNewClient();
        SaveLineInFile(fileName,ConvertRecordToLine(client,"#//#"));
}
void AddClientsInFile (string fileName){
    do{
        cout<<"Adding new client :\n";
        AddOneClient(fileName);
        cout<<"Client added successfully,";
    }while (inputuser::YesOrNo(" do you want to add more client ?"));

}
int main (){
    AddClientsInFile ("ClientFile.txt");
    return 0 ;
}