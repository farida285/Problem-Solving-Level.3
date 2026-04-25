#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <fstream>
using namespace std ;
const string clientsFileName = "BankClients.txt";

const string separator ="#//#";
struct stClient {
    string accountNumber ;
    string  pinCode ;
    string name;
    string phoneNumber ;
    double accountBalance ;
    bool markAsDelete = false;
};

enum enOperation {nothing,clientsList,addClients,deleteClient,updateClient,findClient,transaction,logout};
enum enTransaction {deposit=1,withdraw,totalBalances,mainMenu};
unsigned short PositiveShortNumberInRange (const string &message , short from , short to ){
    int number ;

    do{
        cout<<message;
        if (!(cin >> number))  
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
        }else if(number<from||number>to){
            cout<<"Unavailable number!!\n" ;
            cout<<"Enter number in range from "<<from<<" to "<<to<<".\n";
        }else{
             return (unsigned short)number ;
        }
    }while(true);
   
}
double DoublePositiveNumber(const string &message){
    double number;

    while (true){
        cout << message;

        if (cin >> number){
            if (number >= 0){
                return number; 
            } else {
                cout << "Invalid input!\nPlease enter a non-negative number:\n";
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!\nPlease enter a number:\n";
        }
    }
}
char MyToLower(char letter){
    if(letter>='A'&&letter<='Z'){
        letter += 32;
    }
    return letter;
}
string LowerAllString (string text){
   for(unsigned int i=0;i<text.size();i++){
    if(text[i]!=' '){
          text[i]=MyToLower(text[i]);
    }
   }
   return text;
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
 int size =(int)s1.length();
    for(int i =(int)size-1 ;i>=0;i--){
        if(s1[i] != ' '){
            return (s1.substr(0,i+1));
        }
    }
    return "";   
    
}
string  Trim (const string &s1){

    return (TrimLeft(TrimRight(s1)));   
}
string GetStringInSize (const string &message,unsigned short from=1,unsigned short to=6000,const string &errormessage){
    string text ;
    unsigned size ;
    cout << message;
    do{
        getline(cin>>ws,text) ;
        text=Trim(text);
        size=text.size() ;
        if(size>to||size<from){
            cout <<errormessage;
        }
    }while(size>to||size<from) ;
    return text ;
}
bool IsValidPhoneNumber (const string &text ){
    for(unsigned short i =0; i<text.size();i++){
        if(!(isdigit(text[i]))){
            return 0;
        }
    }
    return 1 ;
}
string GetPhoneNumber (const string &message,unsigned short mustSize){
    string text ;
    unsigned size ;
    bool invalid ;
    do{
        cout <<message;
        getline(cin>>ws,text) ;
        text=Trim(text);
        size=text.size() ;
        if(size!=mustSize){
            cout <<"The phone number must be "<<mustSize<<" digits.\n";
        }
        if(invalid=(!(IsValidPhoneNumber(text)))){
            cout<<"Invalid Phone Number (contains letters).\n";
        }
    }while(size!=mustSize||invalid) ;
    return text ;
}
bool YesOrNo (const string &message){
    string Answer ;
    cout<<message<<endl;
    do{
        cin>>Answer ;
        Answer=LowerAllString(Answer);

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
void PrintMainMenu (){
    cout<<"=================================================\n";
    cout<<"                Main Menu Screen\n";
    cout<<"=================================================\n";
    cout<<"         [1] Show Clients List.\n";
    cout<<"         [2] Add New Client.\n";
    cout<<"         [3] Delete Client.\n";
    cout<<"         [4] Update Client Info.\n";
    cout<<"         [5] Find Client.\n";
    cout<<"         [6] Transaction.\n";
    cout<<"         [7] Exit.\n";
    cout<<"=================================================\n";
}
void ShowConfirmLogoutScreen (enOperation & oper){
  if(YesOrNo("Are you sure to exit ? Y/N")){
    cout<<endl;
    cout<<"------------------------------------\n";
    cout<<"          Program Ends :-)\n";
    cout<<"------------------------------------\n";
    system("pause > nul");
  }else{
    oper =enOperation::nothing;
  }
}
vector <string> SplitString (string s1,const string & separator){
     vector <string> words ;
     int position=0 ;
     string word ;
     while ((position=s1.find(separator))!=string::npos)
     {
        word=s1.substr(0,position);
        s1.erase(0,position+separator.size());
        if(word!=""){
            words.push_back(word);
        }   
     }
     if(s1!=""){
        words.push_back(s1);
     }
     return words ;
     
     
}
stClient ConvertLineToRecord(const string &s,const string &separator){
   vector <string> split =SplitString(s,separator);
   stClient client ;
   client.accountNumber=split[0];
   client.pinCode=split[1];
   client.name=split[2];
   client.phoneNumber=split[3];
   client.accountBalance=stod(split[4]);
   return client ;
}
string ConvertRecordToLine (const stClient &c1,const string &separator){
    string s1 =c1.accountNumber+separator;
    s1+=c1.pinCode+separator;
    s1+=c1.name+separator;
    s1+=c1.phoneNumber+separator;
    s1+=to_string(c1.accountBalance);
    return s1;
}
vector <stClient> LoadclientsDataFromFile (const string &clientsFileName,const string &separator){
    fstream file ;
    string line;
    vector <stClient> vClients ;
    file.open(clientsFileName,ios::in);
    if(file.is_open()){
       while (getline(file,line))
       { 
         vClients.push_back(ConvertLineToRecord(line,separator));
       }
       file.close();
    }
    return vClients ;
}
void SaveUnMarkedVClientsInFile(const string &clientsFileName,const string &separator,const vector <stClient> &vClients){
 fstream file ;
 file.open(clientsFileName,ios::out);
 if(file.is_open()){
    for(const stClient & c1:vClients){
        if(c1.markAsDelete==false){
            file<<ConvertRecordToLine(c1,separator)<<endl;
        }
    }
    file.close();
 }
}
void PrintOneClientInList (const stClient &client){
  cout <<"| "<<left<<setw(15)<<client.accountNumber;
  cout <<"| "<<left<<setw(9)<<client.pinCode;
  cout <<"| "<<left<<setw(40)<<client.name ;
  cout <<"| "<<left<<setw(13)<<client.phoneNumber;
  cout <<"| "<<left<<setw(15)<<fixed<<setprecision(2)<<client.accountBalance;
  cout <<endl;

}
void PrintAllClientList(const vector <stClient> &vClients){
        
        cout<<"_____________________________________________________________________________________________________\n";
        cout <<"| "<<left<<setw(15)<<"Account Number";
        cout <<"| "<<left<<setw(9)<<"Pin Code";  
        cout <<"| "<<left<<setw(40)<<"Client Name";   
        cout <<"| "<<left<<setw(13)<<"Phone Number";
        cout <<"| "<<left<<setw(15)<<"Balance Number";
        cout<<endl;
        cout<<"_____________________________________________________________________________________________________\n";
        cout<<endl;
        for(const stClient& client :vClients){
            PrintOneClientInList(client);
        }
        cout<<endl;
        cout<<"_____________________________________________________________________________________________________\n";

}
void ShowClientListScreen (){
    vector <stClient> vClients =LoadclientsDataFromFile(clientsFileName,separator);
    if(vClients.size()>0){
        cout<<"                                     Client List ("<<vClients.size()<<") Client(s).\n";
        PrintAllClientList(vClients);
    }else{
        cout<<"There are no clients yet !!!\n";
    }
}
bool AccountNumberIsExitInVClients (const vector<stClient> &vClients,const string &accountNumber ){
 for(const stClient &c1 : vClients){
    if(c1.accountNumber==accountNumber){
        return 1 ;
    }
 }
 return 0 ;
 
}
stClient InputNewClientData (const vector<stClient> &vClients){
  stClient c1 ;
  bool existAcc ;
  do{
    c1.accountNumber=GetStringInSize("Please enter Account Number:",1,4,"Enter from 1 to 4 Charcter:");
    if(existAcc=AccountNumberIsExitInVClients(vClients,c1.accountNumber)){
        cout<<"\nClient with ["<<c1.accountNumber<<"] is already exists.\n\n";
    }
  }while (existAcc);
  c1.pinCode=to_string(PositiveShortNumberInRange("Enter Pin Code:",1000,9999));
  c1.name=GetStringInSize("Enter Name:",4,40,"The maximum you can enter is the full three-part name\nEnter Name:");
  c1.phoneNumber=GetPhoneNumber("Enter Phone Number:",11);
  c1.accountBalance=DoublePositiveNumber("Enter Account Balance:");
  return c1 ;
}
void ShowAddNewClientsScreen (){
    cout<<"------------------------------------\n";
    cout<<"      Add New Clients Screen\n";
    cout<<"------------------------------------\n";
    fstream file ;
    vector<stClient> vClients =LoadclientsDataFromFile(clientsFileName,separator);
    file.open(clientsFileName,ios::app|ios::out);
    if(file.is_open()){
     stClient c1;
      do{
        cout<<"\nAdd new client :\n\n";
        c1=InputNewClientData(vClients);
        vClients.push_back(c1);
        file<<ConvertRecordToLine(c1,separator)<<endl;
        cout<<"\nThe client has been added successfully. :-)\n";
       }while(YesOrNo("Do you want add more client ? yes/no"));
       file.close();
     }
}
bool ClientIsExistsInFileByAccNum(const string &clientsFileName,const string &separator,string accountNumber,stClient &c1){
   fstream file;
   string line;
   stClient c ;
   file.open(clientsFileName,ios::in);
   if(file.is_open()){
    while (getline(file,line))
    {  
        c=ConvertLineToRecord(line,separator);
        if(c.accountNumber==accountNumber){
            c1=c;
            file.close();
            return 1;
        }
    }
    file.close();
   }
       return 0;
}
void PrintClientCard (const stClient &c1){
    cout<<"The following are the client details :\n";
    cout<<"Accout Number  :"<<c1.accountNumber<<endl;
    cout<<"Pin Code       :"<<c1.pinCode<<endl;
    cout<<"Client Name    :"<<c1.name<<endl;
    cout<<"Phone Number   :"<<c1.phoneNumber<<endl;
    cout<<"Accout Balance :" <<fixed<<setprecision(2)<<c1.accountBalance<<endl;

}
void MarkClientAsDelete(vector <stClient> &vClients,string accountNumber){
  for(stClient &c1:vClients){
    if(c1.accountNumber==accountNumber){
        c1.markAsDelete=true;
        return ;
    }
  }
}
void DeleteClientFromFile(const string &clientsFileName,const string &separator,string accountNumber){
  vector <stClient> vClients = LoadclientsDataFromFile(clientsFileName,separator);
   MarkClientAsDelete(vClients,accountNumber);
   SaveUnMarkedVClientsInFile(clientsFileName,separator,vClients);
}
void ShowDeleteClientScreen(){
    cout<<"------------------------------------\n";
    cout<<"        Delete Client Screen\n";
    cout<<"------------------------------------\n";
    string accountNumber=GetStringInSize("Please enter Account Number:",1,4,"Enter from 1 to 4 Charcter:");
    stClient c1;
    if(ClientIsExistsInFileByAccNum(clientsFileName,separator,accountNumber,c1)){
        cout<<endl;
        PrintClientCard(c1);
        if(YesOrNo("Are you sure you want delete this client ? Yes/No ?")){
            DeleteClientFromFile(clientsFileName,separator,accountNumber);
            cout<<"\n+++The client has been deleted successfully.+++\n\n";
        }

    }else{
        cout<<"\nClient with Account Number ["<<accountNumber<<"] is Not Found.\n\n";
    }

}
stClient InputUpdateData(const string &accountNumber){
    stClient c1 ;
    c1.accountNumber=accountNumber;
    c1.pinCode=to_string(PositiveShortNumberInRange("Enter Pin Code:",1000,9999));
    c1.name=GetStringInSize("Enter Name:",4,40,"The maximum you can enter is the full three-part name\nEnter Name:");
    c1.phoneNumber=GetPhoneNumber("Enter Phone Number:",11);
    c1.accountBalance=DoublePositiveNumber("Enter Account Balance:");
    return c1 ;
}
void UpdateClientInFile(const string &clientsFileName,const string &separator,const string &accountNumber){
   vector <stClient> vClients = LoadclientsDataFromFile(clientsFileName,separator);
   for(stClient & c1:vClients){
    if(c1.accountNumber==accountNumber){
        c1=InputUpdateData(accountNumber);
        break;
    }
   }
   SaveUnMarkedVClientsInFile(clientsFileName,separator,vClients);
}
void ShowUpdateClientInfoScreen (){
    cout<<"------------------------------------\n";
    cout<<"        Update Client Screen\n";
    cout<<"------------------------------------\n\n";
    string accountNumber=GetStringInSize("Please enter Account Number:",1,4,"Enter from 1 to 4 Charcter:");
    stClient c1;
    if(ClientIsExistsInFileByAccNum(clientsFileName,separator,accountNumber,c1)){
        cout<<endl;
        PrintClientCard(c1);
        if(YesOrNo("Are you sure you want Update this client ? Yes/No ?")){
            cout<<endl;
            UpdateClientInFile(clientsFileName,separator,accountNumber);
            cout<<"\nThe client has been Updated successfully.\n\n";
        }

    }else{
        cout<<"\nClient with Account Number ["<<accountNumber<<"] is Not Found.\n\n";
    }

}
void ShowFindClientScreen(){
    cout<<"------------------------------------\n";
    cout<<"        Find Client Screen\n";
    cout<<"------------------------------------\n\n";
    string accountNumber=GetStringInSize("Please enter Account Number:",1,4,"Enter from 1 to 4 Charcter:");
    stClient c1;
    if(ClientIsExistsInFileByAccNum(clientsFileName,separator,accountNumber,c1)){
        cout<<endl;
        PrintClientCard(c1);
    }else{
        cout<<"\nClient with Account Number ["<<accountNumber<<"] is Not Found.\n\n";
    }

}
void PrintTransactionMenu (){
    cout<<"=================================================\n";
    cout<<"             Transaction Menu Screen\n";
    cout<<"=================================================\n";
    cout<<"         [1] Deposit.\n";
    cout<<"         [2] Withdraw.\n";
    cout<<"         [3] Total Balances.\n";
    cout<<"         [4] Main Menu.\n";
    cout<<"=================================================\n";
}
void  UpdateBalanceByAccNum(const string &clientsFileName,const string &separator,const string &accountNumber,double amount){
   vector <stClient> vClients = LoadclientsDataFromFile(clientsFileName,separator);
   for(stClient & c1:vClients){
    if(c1.accountNumber==accountNumber){
        c1.accountBalance+=amount;
        break;
    }
   }
   SaveUnMarkedVClientsInFile(clientsFileName,separator,vClients);
}
double GetAmount(const string & message){
 double amount;
      do{
         amount =DoublePositiveNumber(message);
          if(amount==0){
            cout <<"\nPlease enter a deposit greater than zero.\n";
           }
        }while(amount==0);
  return amount ;
}
void ShowDepositScreen (){
    cout<<"------------------------------------\n";
    cout<<"          Deposit Screen\n";
    cout<<"------------------------------------\n\n";
    stClient c1;
    string accountNumber;
    short count =0;
    do{
    accountNumber=GetStringInSize("Please enter Account Number:",1,4,"Enter from 1 to 4 Charcter:");
       if(ClientIsExistsInFileByAccNum(clientsFileName,separator,accountNumber,c1)){
          PrintClientCard(c1);
          cout<<endl;
          double amount=GetAmount("Please enter deposit amount ?");
            if(YesOrNo("Are you sure you want to perform this transaction? (Yes/No)")){
               UpdateBalanceByAccNum(clientsFileName,separator,accountNumber,amount);
               cout<<"\nThe amount has been successfully added to the account.\n";
            }
          break;

        }else{
           cout<<"Client with ["<<accountNumber<<"] does not exist.\n";
           count++;
        }
    }
    while(count<3);
    if(count==3){
        cout<<"\nYou have reached the maximum number of incorrect attempts. Please try again later.\n";
    }

}
void ShowWithdrawScreen (){
    cout<<"------------------------------------\n";
    cout<<"          Withdraw Screen\n";
    cout<<"------------------------------------\n\n";
    stClient c1;
    string accountNumber;
    short count =0;
    do{
    accountNumber=GetStringInSize("Please enter Account Number:",1,4,"Enter from 1 to 4 Charcter:");
       if(ClientIsExistsInFileByAccNum(clientsFileName,separator,accountNumber,c1)){
          PrintClientCard(c1);
          cout<<endl;
          double amount ;
          do{amount=GetAmount("Please enter withdraw amount ?");
             if (amount>c1.accountBalance){
                cout<<"\nThis withdrawal amount is greater than the balance in this account, you can withdraw up to : "<<c1.accountBalance<<endl;
             }
            }while (amount>c1.accountBalance);

          if(YesOrNo("Are you sure you want to perform this transaction? (Yes/No)")){
               UpdateBalanceByAccNum(clientsFileName,separator,accountNumber,-1*amount);
               cout<<"\nThe amount has been successfully withdrawn from the account.\n";
            }

          break;
          
        }else{
           cout<<"Client with ["<<accountNumber<<"] does not exist.\n";
           count++;
        }
    }
    while(count<3);
    if(count==3){
        cout<<"\nYou have reached the maximum number of incorrect attempts. Please try again later.\n";
    }

}
void PrintOneClientInBalanceList (const stClient &client){
  cout <<"| "<<left<<setw(16)<<client.accountNumber;
  cout <<"| "<<left<<setw(49)<<client.name ;
  cout <<"| "<<left<<setw(27)<<fixed<<setprecision(2)<<client.accountBalance;
  cout <<endl;

}
void PrintTotalBalance(const vector <stClient> &vClients){
 double totalBalances =0;
 for(const stClient & c1:vClients ){
    totalBalances+=c1.accountBalance;
 }
 cout<<"                                     Total Balances = "<<totalBalances<<endl;
}
void PrintBalanceList(const vector <stClient> &vClients){
        
        cout<<"_____________________________________________________________________________________________________\n";
        cout <<"| "<<left<<setw(16)<<"Account Number";
        cout <<"| "<<left<<setw(49)<<"Client Name";   
        cout <<"| "<<left<<setw(27)<<"Balance Number";
        cout<<endl;
        cout<<"_____________________________________________________________________________________________________\n";
        cout<<endl;
        for(const stClient& client :vClients){
            PrintOneClientInBalanceList(client);
        }
        cout<<endl;
        cout<<"_____________________________________________________________________________________________________\n";
        PrintTotalBalance(vClients);

}
void  ShowTotalBalanceScreen(){
    vector <stClient> vClients =LoadclientsDataFromFile(clientsFileName,separator);
    if(vClients.size()>0){
        cout<<"                                     Balance List ("<<vClients.size()<<") Client(s).\n";
        PrintBalanceList(vClients);

    }else{
        cout<<"There are no clients yet !!!\n";
    }
}
void ExecuteTransactionOperation (const enTransaction &oper){
    system("cls");
    switch (oper)
    {
    case enTransaction::deposit :
        ShowDepositScreen();
        break;
    case enTransaction::withdraw :
        ShowWithdrawScreen();
        break;
    case enTransaction::totalBalances :
        ShowTotalBalanceScreen();
        break;   
    default:
        break;
    }
      cout<<"Press any key to go back to Transaction Screen...";
      system("pause > nul");
}
void ShowTransactionScreen(){
    enTransaction operationNumber ;
 do {
    system("cls");
    PrintTransactionMenu ();
    operationNumber = (enTransaction)PositiveShortNumberInRange("Choose what do you want to do? [1 to 4]?\n",1,4);
    if(operationNumber!=enTransaction::mainMenu){
        ExecuteTransactionOperation(operationNumber );
    }
  }while(operationNumber!=enTransaction::mainMenu);
}
void ExecuteOperation (enOperation & oper){
    
    if(oper!=enOperation::transaction){
        system("cls");
    }
    switch (oper)
    {
    case enOperation::logout:
      
        ShowConfirmLogoutScreen(oper) ;
        break;
    case  enOperation::clientsList:
        ShowClientListScreen ();
        break;
    case enOperation::addClients:
       ShowAddNewClientsScreen();
       break;
    case enOperation::deleteClient:
        ShowDeleteClientScreen();
        break;
    case enOperation::updateClient:
        ShowUpdateClientInfoScreen ();
        break;
    case enOperation::findClient:
        ShowFindClientScreen();
        break;
    case enOperation::transaction:
        ShowTransactionScreen();
        break;
    default:
        break;
    }
    if(oper!=enOperation::logout&&oper!=enOperation::transaction){
        cout<<"Press any key to go back to main menu...";
        system("pause > nul");
    }

}
void OpenBankSystem (){
 enOperation operationNumber;
   do{  
        system("cls");
        PrintMainMenu ();
        operationNumber = (enOperation)PositiveShortNumberInRange("Choose what do you want to do? [1 to 7]?\n",1,7);
        ExecuteOperation (operationNumber);
     }while(operationNumber!=enOperation::logout);

}

int main (){
   OpenBankSystem ();
    return 0;
}