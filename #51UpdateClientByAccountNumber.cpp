//Write a program to Update client by AccountNumber :
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "MyLib.h"
using namespace std ;
struct stClient {
    string accountNumber ;
    string  pinCode ;
    string name;
    string phoneNumber ;
    double accountBalance ;
    bool markAsDelete = false;
};
string ConvertRecordToLine(const stClient &c1,const string &separator="#//#"){
    string s1 ="";
    s1+=c1.accountNumber+separator;
    s1+=c1.pinCode+separator;
    s1+=c1.name+separator;
    s1+=c1.phoneNumber+separator;
    s1+=to_string(c1.accountBalance);
    return s1 ;
}
stClient ConvertLineToRecord(const string &s1,const string &separator){
    stClient c1 ;
    vector<string> vstring =mystring::SplitString(s1,separator);
    c1.accountNumber=vstring[0];
    c1.pinCode=vstring[1];
    c1.name=vstring[2];
    c1.phoneNumber=vstring[3];
    c1.accountBalance=stod(vstring[4]);
    return c1 ;
}
vector <stClient> ReadclientsvectorFromFile (const string &fileName,const string &separator){
    fstream myfile ;
    vector <stClient> vclients;
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
void PrintClient (const stClient & client )
{
    cout<<"The following are the client details :\n";
    cout<<"Accout Number  :"<<client.accountNumber<<endl;
    cout<<"Pin Code       :"<<client.pinCode<<endl;
    cout<<"Client Name    :"<<client.name<<endl;
    cout<<"Phone Number   :"<<client.phoneNumber<<endl;
    cout<<"Accout Balance :" <<fixed<<setprecision(2)<<client.accountBalance<<endl;

}
bool SearchClientByAccountNumber(const vector <stClient> &vclients,const string & searchAccountNumber,stClient &client ){
    for(const stClient &Sclient : vclients){
        if(Sclient.accountNumber==searchAccountNumber){
             client=Sclient;
            return 1;
        }
    }
     return 0;
}
void SaveUnMarkedVClientsInFile(const string &fileName,const string &separator,const vector <stClient> &vclients){
  fstream myfile ;
  myfile.open(fileName,ios::out);
  if(myfile.is_open()){
    for(const stClient& client : vclients){
        if(client.markAsDelete==false){
            myfile<<ConvertRecordToLine(client,separator)<<endl;
        }
    }
    myfile.close();
  }
}
stClient ReadUpdateInformationOf (const string & searchAccountNumber){
    stClient c1;
    c1.accountNumber= searchAccountNumber;
    c1.pinCode=inputuser::GetStringInSize("Enter pinCode ?",4,4);
    c1.name=inputuser::InputStringFromUser("Enter name ?");
    c1.phoneNumber=inputuser::GetStringInSize("Enter phone number ?",11,11);
    c1.accountBalance=inputuser::FloatNumber("Enter account Balance ?");
    return c1 ;
} 
void UpdateClientInVectorByAccountNumber(vector <stClient> &vclients,const string & searchAccountNumber,const stClient updatecClient){
        for( stClient &Sclient : vclients){
        if(Sclient.accountNumber==searchAccountNumber){
             Sclient=updatecClient;
             break;
        }
         }

}
void UpdateClientFromFileAndVectorByAccountNumber(const string &fileName,const string &separator, vector <stClient> &vclients,const string & searchAccountNumber){   
    UpdateClientInVectorByAccountNumber(vclients, searchAccountNumber,ReadUpdateInformationOf (searchAccountNumber));
     SaveUnMarkedVClientsInFile(fileName,separator,vclients);
}
void UpdateClientByAccountNumberFromFile(const string &fileName,const string &separator,const string  &searchAccountNumber){
    vector <stClient> vclients =ReadclientsvectorFromFile(fileName,separator);
    stClient client ;
    if(SearchClientByAccountNumber(vclients,searchAccountNumber,client)){
        PrintClient(client);
         if(inputuser::YesOrNo("Are you sure you want Update this client?")){
             UpdateClientFromFileAndVectorByAccountNumber(fileName,separator,vclients,searchAccountNumber);
            cout<<"\n\nClient Updated Successfully.";
        }


    }else{
        cout << "\nClient with Account Number (" << searchAccountNumber <<") is Not Found!";
    }

}
int main (){
    UpdateClientByAccountNumberFromFile("ClientFile.txt","#//#",inputuser::InputStringFromUser("Please enter Account Number ?"));


    return 0;

}