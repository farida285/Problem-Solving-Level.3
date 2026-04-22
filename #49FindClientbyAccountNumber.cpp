//Write a program to find client by AccountNumber and print it to the screen:
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "MyLib.h"
using namespace std ;
struct stclient {
    string accountNumber ;
    string  pinCode ;
    string name;
    string phoneNumber ;
    double accountBalance ;
};

stclient ConvertLineToRecord(const string &s1,const string separator){
    stclient c1 ;
    vector<string> vstring =mystring::SplitString(s1,separator);
    c1.accountNumber=vstring[0];
    c1.pinCode=vstring[1];
    c1.name=vstring[2];
    c1.phoneNumber=vstring[3];
    c1.accountBalance=stod(vstring[4]);
    return c1 ;
}
vector <stclient> ReadclientsvectorFromFile (const string fileName,const string separator){
    fstream myfile ;
    vector <stclient> vclients;
    myfile.open(fileName,ios::in);
    if(myfile.is_open()){
        string line;
       while ( getline(myfile,line))
       {
        vclients.push_back(ConvertLineToRecord(line,separator));
       }
       myfile.close();
    }
    return vclients ;    
}
void PrintClient (const stclient & client )
{
    cout<<"The following are the client details :\n";
    cout<<"Accout Number  :"<<client.accountNumber<<endl;
    cout<<"Pin Code       :"<<client.pinCode<<endl;
    cout<<"Client Name    :"<<client.name<<endl;
    cout<<"Phone Number   :"<<client.phoneNumber<<endl;
    cout<<"Accout Balance :" <<client.accountBalance<<endl;

}
bool SearchClientByAccountNumber(const vector <stclient> &vclients,string searchAccountNumber,stclient &client ){
    for(const stclient &Sclient : vclients){
        if(Sclient.accountNumber==searchAccountNumber){
             client=Sclient;
            return 1;
        }
    }
     return 0;
}
int main (){
    stclient client;
    vector <stclient> vclients =ReadclientsvectorFromFile("ClientFile.txt","#//#");
    string searchAccountNumber =inputuser::InputStringFromUser("Please enter Account Number ?");
    if(SearchClientByAccountNumber(vclients,searchAccountNumber,client )){
        PrintClient(client);
    }else{
        cout << "\nClient with Account Number (" << searchAccountNumber <<") is Not Found!";
    }
  

    return 0;

}