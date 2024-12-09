//music library
#include <iostream>
#include <string>
using namespace std;
struct node{
    int music_id;
    string musicName;
    float album_price;
    string music_composer;
    struct node *next;
};
node *head = 0;
void insert_first(){
    node *newnode = new node;
    cout << "Enter music ID: ";
    cin >> newnode->music_id;
    cout << "Enter music Name: ";
    cin >> newnode->musicName;
    cout << "Enter the price of music album: ";
    cin >> newnode->album_price;
    cout << "Enter name of music composer: ";
    cin >> newnode->music_composer;
    newnode->next = head;
    head = newnode;
    cout << "music recorded at the first position." << endl;
}
void insert_last(){
    node *newnode = new node;
    cout << "Enter music ID: ";
    cin >> newnode->music_id;
    cout << "Enter music Name: ";
    cin >> newnode->musicName;
    cout << "Enter music_album price: ";
    cin >> newnode->album_price;
    cout << "Enter name of music composer: ";
    cin >> newnode->music_composer;
    node *temp = head;
    while (temp->next != 0){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = 0;
    cout << "Donation recorded at the last position." << endl;
}

void insert_at_position(){
    int pos = 0, count = 0, i = 0;
    cout << "Enter the position where you want to add :";
    cin >> pos;
    node *temp = head;
    while (temp != 0){
        temp = temp->next;
        count++;
    }
    if (pos > count){
        cout << "Invalid Position" << endl;
    }
    else{
        temp = head;
        while (pos < 0 || pos > count){
            temp = temp->next;
            i++;
        }
    }
    node *newnode = new node;
    cout << "Enter music ID: ";
    cin >> newnode->music_id;
    cout << "Enter music Name: ";
    cin >> newnode->musicName;
    cout << "Enter music_album price: ";
    cin >> newnode->album_price;
    cout << "Enter name of music composer: ";
    cin >> newnode->music_composer;

    temp = head;
    for (int i = 0; i < pos - 1; i++){
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    cout << "Music recorded at  position " << pos << "." << endl;
}
void display(){
    node *temp = head;
    cout << "Id\tName\tPrice" << endl;
    while (temp != 0){
        cout << temp->music_id << "\t\t" << temp->musicName << "\t\t" << temp->album_price << "\t\t" << temp->music_composer << endl;
        temp = temp->next;
    }
}

void delete_first(){
    if (head == 0){
        cout << "list is empty" << endl;
    }
    else{
        node *temp = head;
        head = head->next;
        delete temp;
        cout << "Donation deleted from the first position." << endl;
    }
}
void delete_last(){
    struct node *prenode;
    node *temp = head;
    while (temp->next != 0){
        prenode = temp;
        temp = temp->next;
    }
    prenode->next = 0;
    delete temp;
    cout << "Music deleted from the last position." << endl;
}
void delete_at_position(){
    struct node *nextnode;
    int pos = 0, i, count = 0;
    node *temp = head;
    cout << "Enter the position where you want to add :";
    cin >> pos;
    while (temp != 0){
        temp = temp->next;
        count++;
    }
    if (pos > count){
        cout << "Invalid Position" << endl;
    }
    else{
        temp = head;
        while (i < pos){
            temp = temp->next;
            i++;
        }
    }
    temp = head;
    for (int i = 0; i < pos - 1; i++){
        temp = temp->next;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    delete nextnode;
    cout << "Music recorded deleted at position " << pos << "." << endl;
}

int main(){
    int ch, k, n;
    do{
        cout << "Menu\n1.Insert at first\n2.Insert at last\n3.Insert at position\n4.Delete at first\n5.Delete at last\n6.Delete at position\n7.Display\nExite\nEnter your choice:";
        cin >> ch;
        switch (ch){
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