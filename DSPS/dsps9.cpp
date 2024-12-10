// #include<iostream>
// using namespace std;
// struct Node{
//     int id;
//     string name;
//     long contact_info;
//     double amount;
//     Node *next;
//     Node(string n,int i,long c,double amt){
//         id = i;
//         name = n;
//         contact_info = c;
//         amount = amt;
//         next = NULL;
//     }
// };
// class charityManagementSystem{
//     public:
//     Node *head;
//     charityManagementSystem(){
//         head = NULL;
//     }
//     void addDonor(string name,int id,long contact_info,double amount){
//         Node *newNode = new Node(name,id,contact_info,amount);
//         if(head==NULL){
//             head = newNode;
//         }else{
//             Node *temp = head;
//             while(temp->next!=NULL){
//                 temp = temp->next;
//             }
//             temp->next = newNode;
//         }
//     }
//     void display(){
//         if(head==NULL){
//             cout<<"No donors available"<<endl;
//             return;
//         }
//         Node* temp = head;
//         while(temp!=NULL){
//             cout<<"ID :"<<temp->id<<"\nNAME :"<<"Contact Info :"<<temp->contact_info<<"\nAmount :"<<temp->amount<<endl;
//             temp = temp->next;
//         }
//     }
// };
// int main(){
//     charityManagementSystem c;
//     c.addDonor("mahesh",144,1234567890,50000.01);
//     c.addDonor("Rohit",101,1234567890,56300.01);
//     c.addDonor("Virat",102,1234567890,1000.01);
//     c.display();
//     return 0;
// }


//charity mgnt system
#include <iostream>
#include <string>
using namespace std;
struct node
{
    int donorID;
    string donorName;
    float donationAmount;
    string donationDate;
    struct node *next;
};

node *head = 0;
void insert_first()
{
    node *newnode = new node;
    cout << "Enter Donor ID: ";
    cin >> newnode->donorID;
    cout << "Enter Donor Name: ";
    cin >> newnode->donorName;
    cout << "Enter Donation Amount: ";
    cin >> newnode->donationAmount;
    cout << "Enter Donation Date (DD/MM/YYYY): ";
    cin >> newnode->donationDate;
    newnode->next = head;
    head = newnode;
    cout << "Donation recorded at the first position." << endl;
}
void insert_last()
{
    node *newnode = new node;
    cout << "Enter Donor ID: ";
    cin >> newnode->donorID;
    cout << "Enter Donor Name: ";
    cin >> newnode->donorName;
    cout << "Enter Donation Amount: ";
    cin >> newnode->donationAmount;
    cout << "Enter Donation Date (DD/MM/YYYY): ";
    cin >> newnode->donationDate;
    node *temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = 0;
    cout << "Donation recorded at the last position." << endl;
}

void insert_at_position()
{
    int pos = 0, count = 0, i = 0;

    cout << "Enter the position where you want to add :";
    cin >> pos;
    node *temp = head;
    while (temp != 0)
    {
        temp = temp->next;
        count++;
    }
    if (pos > count)
    {
        cout << "Invalid Position" << endl;
    }
    else
    {
        temp = head;
        while (pos < 0 || pos > count)
        {
            temp = temp->next;
            i++;
        }
    }
    node *newnode = new node;
    cout << "Enter Donor ID: ";
    cin >> newnode->donorID;
    cout << "Enter Donor Name: ";
    cin >> newnode->donorName;
    cout << "Enter Donation Amount: ";
    cin >> newnode->donationAmount;
    cout << "Enter Donation Date (DD/MM/YYYY): ";
    cin >> newnode->donationDate;

    temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    cout << "Donation recorded at  position " << pos << "." << endl;
}

void display()
{
    node *temp = head;
    cout << "Id\tName\tPrice" << endl;
    while (temp != 0)
    {
        cout << temp->donorID << "\t\t" << temp->donorName << "\t\t" << temp->donationAmount << "\t\t" << temp->donationDate << endl;
        temp = temp->next;
    }
}

void delete_first()
{
    if (head == 0)
    {
        cout << "list is empty" << endl;
    }
    else
    {
        node *temp = head;
        head = head->next;
        delete temp;
        cout << "Donation deleted from the first position." << endl;
    }
}
void delete_last()
{
    struct node *prenode;
    node *temp = head;
    while (temp->next != 0)
    {
        prenode = temp;
        temp = temp->next;
    }
    prenode->next = 0;
    delete temp;
    cout << "Donation deleted from the last position." << endl;
}
void delete_at_position()
{
    struct node *nextnode;
    int pos = 0, i, count = 0;
    node *temp = head;
    cout << "Enter the position where you want to add :";
    cin >> pos;
    while (temp != 0)
    {
        temp = temp->next;
        count++;
    }
    if (pos > count)
    {
        cout << "Invalid Position" << endl;
    }
    else
    {
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
    }
    temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    delete nextnode;
    cout << "Donation recorded deleted at position " << pos << "." << endl;
}

int main()
{
    int ch, k, n;
    do
    {
        cout << "Menu\n1.Insert at first\n2.Insert at last\n3.Insert at position\n4.Delete at first\n5.Delete at last\n6.Delete at position\n7.Display\nExite\nEnter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            insert_first();
            break;
        case 2:
            insert_last();
            break;
        case 3:
            insert_at_position();
            break;
        case 4:
            delete_first();
            break;
        case 5:
            delete_last();
            break;
        case 6:
            delete_at_position();
            break;
        case 7:
            display();
            break;
        case 8:
        default:
            cout << "Wrong choice" << endl;
        }
        cout << "if you want to continue enter 1:";
        cin >> k;

    } while (k == 1);
    return 0;
}