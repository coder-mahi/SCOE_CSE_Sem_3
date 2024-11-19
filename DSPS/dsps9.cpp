// charity management system
#include<iostream>
using namespace std;
struct Node{
    int id;
    string name;
    long contact_info;
    double amount;
    Node *next;
    Node(string n,int i,long c,double amt){
        id = i;
        name = n;
        contact_info = c;
        amount = amt;
        next = NULL;
    }
};
class charityManagementSystem{
    public:
    Node *head;
    charityManagementSystem(){
        head = NULL;
    }
    void addDonor(string name,int id,long contact_info,double amount){
        Node *newNode = new Node(name,id,contact_info,amount);
        if(head==NULL){
            head = newNode;
        }else{
            Node *temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void display(){
        if(head==NULL){
            cout<<"No donors available"<<endl;
            return;
        }
        Node* temp = head;
        while(temp!=NULL){
            cout<<"ID :"<<temp->id<<"\nNAME :"<<"Contact Info :"<<temp->contact_info<<"\nAmount :"<<temp->amount<<endl;
            temp = temp->next;
        }
    }
};
int main(){
    charityManagementSystem c;
    c.addDonor("mahesh",144,1234567890,50000.01);
    c.addDonor("Rohit",101,1234567890,56300.01);
    c.addDonor("Virat",102,1234567890,1000.01);
    c.display();
    return 0;
}