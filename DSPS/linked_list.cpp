#include<iostream>
using namespace std;
struct book{
    string title,author,isbn;
    bool avail;
    book* next;
    book(string t,string a, string i,bool isavail){
        title = t;
        author = a;
        isbn = i;
        avail = isavail;
        next = nullptr;
    }
};
class Library{
    book* head;
    public:
    Library(){
        head = NULL;
    }
    void addBook(string t,string a, string i,bool isavail){
        book* newBook = new book(t,a,i,isavail);
        if(head==NULL){
            head = newBook;
        }else{
            book* temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newBook;
        }
        cout<<"Book added successfully :"<<endl;
    }
    void searchBook(string title){
        bool found = false;
        if(head==NULL){
            cout<<"Library is EMpty"<<endl;
        }else{
            book* temp = head;
            while(temp!=NULL){
                if(temp->title==title){
                    cout<<"Book Found..."<<endl;
                    cout<<"Title : "<<temp->title;
                    cout<<"Author : "<<temp->author;
                    cout<<"ISBN : "<<temp->isbn;
                    cout<<"Avaibility : "<<(temp->avail ? "Available" : "Not Available")<<endl;
                    return ;
                }
                temp = temp->next;
            }
            cout<<"Book Not found"<<endl;
        }
    }
    void deleteBook(string isbn){
        bool found = false;
        if(head==NULL){
            cout<<"Library is EMpty"<<endl;
        }
        if(head->isbn == isbn){
            book* temp = head;
            head = head->next;
            delete temp;
            return ;
        }
        book* temp = head;
        while(temp->next!=NULL && temp->next->isbn!=isbn){
            temp= temp->next;
        }
        if(temp->next==NULL){
            cout<<"Book Not found";
        }else{
            found = true;
            cout<<"Book  deleted!!!";
            book* todelete = temp->next;
            temp->next = todelete->next;
            delete todelete;
        }
        if(!found){
            cout<<"Book Not found..!"<<endl;
        }
    }
    void display(){
        if(head==NULL){
            cout<<"empty";
        }else{
            for(book* temp = head;temp;temp=temp->next){
                cout<<"Title : "<<temp->title<<endl; 
                cout<<"Author : "<<temp->author<<endl; 
                cout<<"ISBN : "<<temp->isbn<<endl; 
                cout<<endl;
            }
        }
    }
};
int main(){
    Library b;
    string title,isbn;
    b.addBook("xyz","auth1","123",true);
    b.addBook("abc","auth2","766",true);
    b.addBook("pqr","auth3","4443",true);
    b.display();
    cout<<"Enter Title of boook to search : "<<endl;
    cin>>title;
    b.searchBook(title);
    cout<<"Enter ISBN of boook to search : "<<endl;
    cin>>isbn;
    b.deleteBook(isbn);
    return 0;
}