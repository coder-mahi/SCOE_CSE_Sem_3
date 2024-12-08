#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void insert(Node*& head,int value){
    Node* newNode;
    newNode = new Node();
    head->data = value;
    head->next = nullptr;
    if(head==nullptr){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next!= nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}
void display(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    Node* head;
    head = nullptr;
    int ch,value;
    char choice;
    do{
    cout<<"select choice\n1.Insert\n2.Display linked list"<<endl;
    cin>>ch;
    switch(ch){
        case 1:
            cout<<"Enter data you want to insert..."<<endl;
            cin>>value;
            insert(head,value);
        case 2:
            display(head);
    }
    cout<<"Do you want to continue (y/n)";
    cin>>choice;
    }while(choice=='y' || choice =='Y');
    return 0;
}