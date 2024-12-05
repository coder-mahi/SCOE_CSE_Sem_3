// Assignment No. 1
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
class Bank
{
public:
    string dname;
    int accno;
    float amt;
    float bal = 0.0;
    int wcount = 0, dcount = 0;
    void accept(string, int, float);
    void deposit(float);
    void withdraw(float);
    void display();
};
void Bank::accept(string name, int acc, float b)
{
    dname = name;
    accno = acc;
    bal = b;
    cout << "\nInput accepted..!" << endl;
}
void Bank::withdraw(float amt)
{
    this->amt = amt;
    bal = bal - amt;
    cout << "Succesfully withdraw...! Available balance: " << bal << endl;
    wcount++;
}
void Bank::deposit(float amt)
{
    this->amt = amt;
    bal += amt;
    cout << "Updated balance: " << bal << endl;
    dcount++;
}
void Bank::display()
{
    cout << left << setw(30) << "| Depositor Name:"
        << " | " << dname << endl;
    cout << left << setw(30) << "| Your Account No:"
         << " | "<< accno << endl;
    cout << left << setw(30) << "| Available Balance:"
         << fixed << setprecision(3) << " | "<< bal << endl;
    cout << left << setw(30) << "| No. of Deposits:"
         << " | "<<dcount << endl;

    cout << left << setw(30) << "| No. of Withdrawals:"
          <<" | "<< wcount << endl;
}
int main()
{
    Bank obj;
    string name;
    int acc, ch;
    float b;
    float amt;
    char c;
    cout << "\n** BANK MANAGEMENT SYSTEM **" << endl;
    cout << "\nEnter Depositor name : ";
    cout << "\nAccount no. : ";
    cout << "\nEnter bank balance : " << endl;
    cin >> name;
    cin >> acc;
    cin >> b;
    obj.accept(name, acc, b);
    do
    {
        cout << "Select your choice :" << endl;
        cout << "1. deposit" << endl;
        cout << "2. withdraw" << endl;
        cout << "3. view balance" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter Deposit ammount..$" << endl;
            cin >> amt;
            obj.deposit(amt);
            break;
        case 2:
            cout << "Enter withdrawl ammount..$" << endl;
            cin >> amt;
            obj.withdraw(amt);
            break;
        case 3:
            obj.display();
            break;
        default:
            exit(0);
            break;
        }
        cout << "\nDo you want to continue ? y/n" << endl;
        cin >> c;
    } while (c == 'y' || c == 'Y');
    return 0;
}