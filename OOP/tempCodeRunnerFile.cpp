#include <iostream>
#include <cstring>
using namespace std;

class Books {
    char *author;
    char *title;
    char *publisher;
    float price;
    int stock;

public:
    Books(const char *auth, const char *titl, const char *publ, float pr, int stk) {
        author = new char[strlen(auth) + 1];
        title = new char[strlen(titl) + 1];
        publisher = new char[strlen(publ) + 1];
        strcpy(author, auth);
        strcpy(title, titl);
        strcpy(publisher, publ);
        price = pr;
        stock = stk;
    }
    ~Books() {
        delete[] author;
        delete[] title;
        delete[] publisher;
    }

    void display() {
        cout << "\nTitle: " << title << "\nAuthor: " << author
             << "\nPublisher: " << publisher << "\nPrice: $" << price
             << "\nStock: " << stock << "\n";
    }

    bool search(const char *searchTitle, const char *searchAuthor) {
        return (strcmp(title, searchTitle) == 0 && strcmp(author, searchAuthor) == 0);
    }

    void buy(int quantity) {
        if (quantity <= stock) {
            cout << "Total cost: $" << quantity * price << "\n";
            stock -= quantity;
        } else {
            cout << "Sorry, not enough stock.\n";
        }
    }
};

int main() {
    Books book1("Marvel", "Mahesh Shinde", "Yeola", 20.50, 50);
    Books book2("Ironman", "Tony Stark", "New York", 15.99, 30);
    char title[50], author[50];
    int numCopies;
    cout << "Enter book title: ";
    cin.getline(title, 50);
    cout << "Enter book author: ";
    cin.getline(author, 50);

    if (book1.search(title, author)) {
        book1.display();
        cout << "Enter number of copies: ";
        cin >> numCopies;
        book1.buy(numCopies);
    } else if (book2.search(title, author)) {
        book2.display();
        cout << "Enter number of copies: ";
        cin >> numCopies;
        book2.buy(numCopies);
    } else {
        cout << "Book not available.\n";
    }
    return 0;
}