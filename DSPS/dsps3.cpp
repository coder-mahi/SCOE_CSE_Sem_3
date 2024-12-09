#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class stud {
public:
    int roll;
    string name;
    string clas;
    int q1,q2,q3,q4,q5;
    void accept() {
        cout << "\nEnter the Roll No.:\t";
        cin >> roll;
        cout << "\nEnter the Name :\t";
        cin >> name;
        cout << "\nEnter the Class:\t";
        cin >> clas;
        cout << "\n";
    }
    void survey()
    {
    	cout<<"\nAnswer the following qustions(YES=1,NO=0):\n";
	cout<<"\nDid you enjoy tne training program:\t";
	cin>>q1;
	cout<<"\nDid training program help you attain knowledge:\t";
	cin>>q2;
	cout<<"\nIs training program help you in attaining skills:\t";
	cin>>q3;
	cout<<"\nWas it inspiring:\t";
	cin>>q4;
	cout<<"\nShould such training program more be conducted:\t";
	cin>>q5;
    }
};

int main() 
{
    int ch, choice, i,n = 0;  
    int temp_roll;
    string temp_name;
    string temp_clas;
    int high, low, mid;
    int temp_r;
    string temp_c;
    string temp_n;
    stud t1[10];
    stud s[10];
    
    do{
        cout << "\n1. Enter Student Data\n2. Display Student Data\n3. Search (Linear Search)\n4. Search (Binary Search)\n5.Survey for students\n6.Overall Result\nEnter your choice:\t";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "\nEnter the following:";
            t1[i].accept();
            s[i].survey();
            n++;
            break;

        case 2:
            cout << "\n";
            cout << "\nStudents Details\n";
            cout << setw(20) << left << "Name" << setw(20) << left << "Roll No." << setw(10) << left << "Class" << endl;
            cout << string(50, '-') << endl;
            for (int i = 0; i < n; i++) {
                cout << setw(20) << left << t1[i].name << setw(20) << left << t1[i].roll << setw(10) << left << t1[i].clas << endl;
            }
            break;

        case 3:
            cout << "\nEnter the Roll No.:\t";
            cin >> temp_roll;
            cout << "\nEnter the Name:\t";
            cin >> temp_name;
            cout << "\nEnter the class:\t";
            cin >> temp_clas;
            for (int i = 0; i < n; i++) {
                if (temp_roll == t1[i].roll && temp_name == t1[i].name && temp_clas == t1[i].clas) {
                    cout << "\nStudent has attended Training Program...\n";
                    break;  
                }
                if (i == n - 1) {  
                    cout << "\nStudent has not attended Training Program...\n";
                }
            }
            break;

        case 4:
            cout << "\nEnter the Roll No.:\t";
            cin >> temp_roll;
            cout << "\nEnter the Name:\t";
            cin >> temp_name;
            cout << "\nEnter the class:\t";
            cin >> temp_clas;
            
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (t1[i].roll > t1[j].roll) {
                        temp_r = t1[i].roll;
                        temp_n = t1[i].name;
                        temp_c = t1[i].clas;
                        t1[i].roll = t1[j].roll;
                        t1[i].name = t1[j].name;
                        t1[i].clas = t1[j].clas;
                        t1[j].roll = temp_r;
                        t1[j].name = temp_n;
                        t1[j].clas = temp_c;
                    }
                }
            }
            low = 0;
            high = n - 1;
            mid = (high + low) / 2;
            while (low <= high) {
                if (temp_roll == t1[mid].roll) {
                    cout << "\nStudent attended Training Program...\n" << endl;
                    break;
                } else if (temp_roll < t1[mid].roll) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
                mid = (low + high) / 2;
            }
            if (low > high) {
                cout << "\nStudent has not attended Training Program...\n";
            }
            break;
	case 5:
	
	break;
        default:
            cout << "\nINVALID CHOICE..";
        }

        cout << "\nPress 1 to continue, 0 to exit:\t";
        cin >> choice;
    }while (choice == 1);

    return 0;
}