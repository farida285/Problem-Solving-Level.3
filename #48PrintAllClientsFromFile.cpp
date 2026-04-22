//Write a program to read clients file and show them on the screen as follows:
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
    vector<string> vstring =mystring::SplitString(s1,"#//#");
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
void Printoneclient (const stclient &client){
    cout<<"| "<<setw(15)<<left<<client.accountNumber<<"| "<<setw(10)<<left<<client.pinCode;
    cout<<"| "<<setw(40)<<left<<client.name;
    cout<<"| "<<setw(12)<<left<<client.phoneNumber;
    cout<<"| "<<setw(12)<<left<<fixed<<setprecision(2)<<client.accountBalance;
    //cout << defaultfloat;
}
void PrintclientsList (const vector <stclient> & vclients){
cout << "\n\t\t\t\t   Client List (" << vclients.size() << ")Client(s).";
cout <<"\n___________________________________________________________________________________________________\n" << endl;
cout << "| " << left << setw(15) << "Accout Number";
cout << "| " << left << setw(10) << "Pin Code";
cout << "| " << left << setw(40) << "Client Name";
cout << "| " << left << setw(12) << "Phone";
cout << "| " << left << setw(12) << "Balance";
cout <<"\n___________________________________________________________________________________________________\n" << endl;
for(const stclient &client : vclients){
    Printoneclient(client);
    cout<<endl;
}
cout <<"\n___________________________________________________________________________________________________\n" << endl;
}
int main (){
    vector <stclient> vclients =ReadclientsvectorFromFile("ClientFile.txt","#//#");
    PrintclientsList(vclients);

    return 0;

}