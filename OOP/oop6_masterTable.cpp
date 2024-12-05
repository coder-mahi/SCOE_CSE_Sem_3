// Student Master Table --updated to simple
#include <iostream>
#include <iomanip>
using namespace std;
class student {
public:
    int roll;
    string name;
    string* sub;

    virtual void accept(int n) {
        cout<<"\nEnter roll:";
        cin>>roll;
        cout<<"Enter name:";
        cin>>name;
        sub=new string[n];
        cout<<"Enter the "<<n<<" subjects:";
        for(int i=0;i<n;i++) {
            cin>>sub[i];
        }
    }
    virtual void display(int n) {
        cout<<left<<setw(10)<<"Roll No"<<setw(15)<<"Name"<<"Subjects\n";
        cout<<setw(10)<<roll<<setw(15)<<name;
        for(int i=0;i<n;i++) {
            cout<<(i+1)<<". "<<sub[i]<<" ";
        }
        cout<<endl;
    }
    ~student() {
        delete[] sub;
    }
};
class academics : public student {
public:
    int* marks, * internal, * external;
    int total=0;

    void accept(int n) {
        student::accept(n);
        internal=new int[n];
        external=new int[n];
        marks=new int[n];

        for(int i=0;i<n;i++) {
            cout<<"\nEnter internal marks of "<<sub[i]<<":";
            cin>>internal[i];
            cout<<"Enter external marks of "<<sub[i]<<":";
            cin>>external[i];
            marks[i]=internal[i]+external[i];
            total+=marks[i];
        }
    }
    void display(int n) {
        student::display(n);
        cout<<left<<setw(10)<<" "<<setw(15)<<" "<<setw(20)<<"Subjects"
             <<setw(15)<<"Internal Marks"<<setw(15)<<"External Marks"<<setw(10)<<"Total\n";
        for(int i=0;i<n;i++) {
            cout<<setw(25)<<" "<<setw(20)<<sub[i]
                 <<setw(15)<<internal[i]<<setw(15)<<external[i]<<setw(10)<<marks[i]<<"\n";
        }
        calculate(n);
    }

    void calculate(int n) {
        int maxMarks=200*n;
        float percentage=(static_cast<float>(total)/maxMarks)*100;
        cout<<"\nPercentage:"<<fixed<<setprecision(2)<<percentage<<"%\n";
    }

    void delete1(int roll_to_delete,int n) {
        if(roll_to_delete==roll) {
            cout<<"\nRecord found and deleted.\n";
            roll=-1;
        } else {
            cout<<"\nRecord not found.\n";
        }
    }

    void edit(int roll_to_edit,int n) {
        if(roll_to_edit==roll) {
            cout<<"\nRecord found. Enter new details:\n";
            accept(n);
        } else {
            cout<<"\nRecord not found.\n";
        }
    }

    void search(int roll_to_search,int n) {
        if(roll_to_search==roll) {
            cout<<"\nRecord found:\n";
            display(n);
        } else {
            cout<<"\nRecord not found.\n";
        }
    }
    ~academics() {
        delete[] internal;
        delete[] external;
        delete[] marks;
    }
};

int main() {
    int n, ch, roll_to_delete, roll_to_search, roll_to_edit;
    student* bptr;
    cout<<"Enter the number of subjects:";
    cin>>n;
    academics ad;
    bptr=&ad;
    do {
        cout<<"\nEnter your choice:\n1) Build a master table\n2) List a table\n3) Insert a new entry\n4) Delete old entry\n5) Edit an entry\n6) Search for a record\n7) Exit\n";
        cin>>ch;

        switch(ch) {
            case 1:
                bptr->accept(n);
                break;

            case 2:
                bptr->display(n);
                break;

            case 3:
                bptr->accept(n);
                break;

            case 4:
                cout<<"\nEnter roll number to delete record:";
                cin>>roll_to_delete;
                ad.delete1(roll_to_delete,n);
                break;

            case 5:
                cout<<"\nEnter roll number to edit record:";
                cin>>roll_to_edit;
                ad.edit(roll_to_edit,n);
                break;

            case 6:
                cout<<"\nEnter roll number to search record:";
                cin>>roll_to_search;
                ad.search(roll_to_search,n);
                break;

            case 7:
                cout<<"\nExiting from the code!";
                return 0;

            default:
                cout<<"\nInvalid choice!";
        }
    } while(ch!=7);

    return 0;
}