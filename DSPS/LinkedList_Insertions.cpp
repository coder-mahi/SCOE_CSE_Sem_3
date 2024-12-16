#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void insertAtBegining(Node* head){
    int val;
    cout<<"Enter Data of Node:"<<endl;
    cin>>val;
    Node* temp = new Node();
    temp->data = val;
    temp->next = head;
    head = temp;
    cout<<"Inserted at beginning :"<<endl;
}
void insertAtEnd(Node* head){
}
void insertAtSpecified(Node* head){

}
void display(Node* head){
    Node* current=head;
    while(current!=nullptr){
        cout<<current->data<<"->";
        current = current->next;
    }
}
int main(){
    Node* head = nullptr;
    int choice,c;
    do{
        cout<<"Select Operation-->"<<endl;
        cout<<"1.Insert at beginning\n2.Insert at end\n3.Insert at specific location\n4.Insert at specific location"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                insertAtBegining(head);
                break;
            case 2:
                insertAtEnd(head);
                break;
            case 3:
                insertAtSpecified(head);
                break;
            case 4:
                display(head);
                break;
            default:
                return 0;
        }
        cout<<"Do you want to continue? (true 1/ false 0)"<<endl;
        cin>>c;
    }while(c==1);
    return 0;
}