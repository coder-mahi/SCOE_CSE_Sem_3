#include<iostream>
using namespace std ;
struct Book {
	string author ;
	string ISBN ;
	string title ;
	bool isava ;
	Book *next ;
	Book(string t, string a , string isbn , bool ava){
		title = t ;
		author = a ;
		ISBN = isbn ;
		isava = ava ;
		next = NULL ;
	}
};
class Books{
	private :
		Book *Head ;
	public :
		Books() : Head(NULL) {
		}
		void addBooks(string title , string author , string ISBN , bool isava){
			Book *newBook = new Book(title,author,ISBN,isava);
			if(Head==NULL){
				Head = newBook ;
				
			}
			else{
				Book *temp ;
				temp = Head ;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				
				temp->next = newBook ;
			}
			cout<<"Book added successfully "<<endl ;
			
		}
		void searchBook(string title){
			
			bool found = false ;
			Book *temp = Head ;
			
			if(Head==NULL){
				cout<<"Library is Empty "<<endl ;
			}
			else{
				while(temp!=NULL){	
					if(temp->title==title){
						cout<<"Bool Found "<<endl;
						cout<<"Title : "<<temp->title<<endl ;
						cout<<"Author : "<<temp->author<<endl ;
						cout<<"ISBN : "<<temp->ISBN<<endl ;
						cout<<"Availability : "<<(temp->isava) ? " Available " : "Not Available ";
						cout<<endl;
						found = true ;
						break ;
					}
					
					temp = temp->next ;
				}
				if(!found){
					cout<<"Book not found "<<endl;
				}
			}
		}
		void removeBook(string ISBN){
			if(Head==NULL){
				cout<<"Library is Empty "<<endl ;
			}
			//Remove from Head
			if(Head->ISBN == ISBN){
				Book *temp = Head ;
				Head = Head->next ;
				delete temp ;
				return  ;
			}
			
			//Remove from other location
			Book *temp = Head ;
			while(temp->next!=NULL && temp->next->ISBN !=ISBN){
				temp = temp->next ;
            }
			if(temp->next==NULL){
				cout<<"Book not found "<<endl ;
			}
			else{
				Book *toDelete = temp->next ;
				temp->next = toDelete->next ;
				delete toDelete ;
				cout<<"Book removed Successfully "<<endl;
			}	
		}
		void Display(){
			Book *temp= Head ;
			if(Head==NULL){
				cout<<"Library is Empty "<<endl ;
			}
			else{
				while(temp!=NULL){
					cout<<"Title : "<<temp->title<<endl;
					cout<<"Author : "<<temp->author<<endl ;
					cout<<"ISBN : "<<temp->ISBN<<endl ;
					cout<<"Availability : "<<(temp->isava) ? " Available " : "Not Available " ;
					cout<<endl;
					cout<<endl;
					temp = temp->next ;
				}
			}
		}
};
int main(){
	Books b ;
	b.addBooks("Flame","mahi123","12334",false);
	b.addBooks("Flame2","mahesh2","123345",true);
		b.addBooks("Flame3","mahesh3","1233456",true);
			b.addBooks("Flame4","mahesh4","1233467",true);	
	cout<<"Displaying all Books "<<endl;
	b.Display() ;
	
	string temp ;
	cout<<"Enter book title for Searching : "<<endl ;
	cin>>temp ;
	b.searchBook(temp) ;
	
	string isbn ;
	cout<<"Enter books ISBN for removing Book "<<endl;
	cin>>isbn;
	
	b.removeBook(isbn) ;
	return 0 ;
	
}