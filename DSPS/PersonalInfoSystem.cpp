#include <iostream>
#include<cstring>
#include<string>
using namespace std;
class PIS{
    int mob,tel,dob;
    char *addr,*name,*policyno;
    public:
    void accept();
    void display();
    PIS(string);
    PIS(){
        mob = 987654321;
        tel = 1234;
        dob = 2005;
        addr = new char;
        name = new char;
        policyno = new char;
        strcpy(name,"mahesh");
        strcpy(addr,"yeola");
        strcpy(policyno,"PLN123");
    }
}obj;
// parametrized constructor outside class
    PIS::PIS(string str){
        cout<<str<<endl;
        cout<<"Parametrized Consructor executed:"<<endl;
    }
    void PIS::accept(){
        cout<<"Enter\nname:\nmob no:\naddress:\ntel no:\nDOB :\npolicy no:"<<endl;
        cin>>name>>mob>>addr>>tel>>dob>>policyno;
    }
    void PIS::display(){
        cout<<"Name : "<<name<<"\tMobile No : "<<mob<<"\tAddress : "<<addr<<"\tTel No : "<<tel<<"\tDateOfBirth : "<<dob<<"\tPolicy no : "<<policyno<<endl;
    }
int main(){
    string str;
    cout<<"Enter something.!"<<endl;
    cin>>str;
    PIS obj2(str);
    obj.accept();
    obj.display();
    return 0;
}