// 7. Hospital Management System --updated to simple
#include<iostream>
using namespace std;
class person{
    public:
    string name;
    int id,mo_no;
};
class doctor:virtual public person{
    public:
    string speciality,education;
    void getdata1(){
        cout<<"\nEnter id: ";
        cin>>id;
        cout<<"\nEnter name: ";
        cin>>name;
        cout<<"\nEnter mobile number: ";
        cin>>mo_no;
        cout<<"\nEnter speciality: ";
        cin>>speciality;
        cout<<"\nEnter education: ";
        cin>>education;
    }
};
class nurse:virtual public person{
    public:
    string dept,ward;
    void getdata2(){
        cout<<"\nEnter id: ";
        cin>>id;
        cout<<"\nEnter name: ";
        cin>>name;
        cout<<"\nEnter mobile number: ";
        cin>>mo_no;
        cout<<"\nEnter ward: ";
        cin>>ward;
        cout<<"\nEnter department: ";
        cin>>dept;
    }
};
class admin:public doctor, public nurse{
    public:
    void search_d(doctor a1[],int n){
        int f=0;
        cout<<"\nEnter the name of doctor to be searched: ";
        cin>>name;
        cout<<"\nEnter ID of doctor to be serached: ";
        cin>>id;

        for(int i=0;i<n;i++){
            if(a1[i].name==name&&a1[i].id==id){
                f=1;
                cout<<"\nDoctor is available!"<<endl;
                cout<<"id\tname\tmobile number\tspeciality\teducation"<<endl;
                cout<<a1[i].id<<"\t"<<a1[i].name<<"\t"<<a1[i].mo_no<<"\t"<<a1[i].speciality<<"\t"<<a1[i].education<<endl;
            }
        }
        if(!f)
        {
          cout<<"Doctor "<<name<<" is not found!";
        }
    }
    void search_n(nurse a2[],int n)
    {
        int f=0;
        cout<<"\nEnter the name of nurse to be searched: ";
        cin>>name;
        cout<<"\nEnter ID of nurse to be serached: ";
        cin>>id;

        for(int i=0;i<n;i++)
        {
            if(a2[i].name==name&&a2[i].id==id)
            {
                f=1;
                cout<<"\nnurse is available!"<<endl;
                cout<<"id\tname\tmobile number\tward\tdept"<<endl;
                cout<<a2[i].id<<"\t"<<a2[i].name<<"\t"<<a2[i].mo_no<<"\t"<<a2[i].ward<<"\t"<<a2[i].dept<<endl;
                
            }
        }
        if(!f)
        {
          cout<<"\nnurse "<<name<<" is not found!";
        }
    }
};
int main()
{
    admin ad;
    doctor dd[10];
    nurse nn[10];
    int ch,n,dn;
     cout<<"\nEnter the number of doctors: ";
     cin>>dn;
     cout<<"\nEnter the number of nurse: ";
     cin>>n;
    do{
        cout<<"\nEnter your choice:\n1. Accept details for doctor:\n2. Accept details for Nurse: \n3. Search doctor: \n4. Search Nurse: \n5.Exit";
        cin>>ch;
        switch(ch)
        {
            case 1:
            for(int i=0;i<dn;i++){
            dd[i].getdata1();}
            break;

            case 2:
           for(int i=0;i<n;i++){
            nn[i].getdata2();}
            break;

            case 3:
            ad.search_d(dd,dn);
            break;

            case 4:
            ad.search_n(nn,n);
            break;

            case 5:
            cout<<"\nExiting from the code!";
            return 0;
            break;

            default:
            cout<<"\nInvalid case!";
        }
        
    }while(ch!=5);
    return 0;
}