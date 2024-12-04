#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For formatted output
using namespace std;

class Book {
private:
    string author;
    string title;
    float price;
    string publisher;
    int stock;

public:
    // Constructor to initialize book details
    Book(string a, string t, float p, string pub, int s)
        : author(a), title(t), price(p), publisher(pub), stock(s) {}

    // Check if the book matches the title and author
    bool isAvailable(const string &t, const string &a) {
        return (title == t && author == a);
    }

    // Display book details
    void displayDetails() {
        cout << setw(15) << left << title
             << setw(15) << author
             << setw(10) << price
             << setw(15) << publisher
             << setw(10) << stock << endl;
    }

    // Process a purchase request
    bool purchase(int copies) {
        if (copies <= stock) {
            stock -= copies;
            cout << "Total Cost: $" << price * copies << endl;
            return true;
        } else {
            cout << "Required copies not in stock." << endl;
            return false;
        }
    }
};

class BookShop {
private:
    vector<Book *> inventory;

public:
    // Add a book to the inventory
    void addBook(string author, string title, float price, string publisher, int stock) {
        inventory.push_back(new Book(author, title, price, publisher, stock));
    }

    // Search for a book by title and author
    void searchBook(const string &title, const string &author) {
        for (auto &book : inventory) {
            if (book->isAvailable(title, author)) {
                cout << "\nBook Found:\n";
                cout << setw(15) << left << "Title"
                     << setw(15) << "Author"
                     << setw(10) << "Price"
                     << setw(15) << "Publisher"
                     << setw(10) << "Stock" << endl;
                cout << string(65, '-') << endl;
                book->displayDetails();

                int copies;
                cout << "Enter the number of copies required: ";
                cin >> copies;
                book->purchase(copies);
                return;
            }
        }
        cout << "Book not available in inventory.\n";
    }

    // Destructor to free allocated memory
    ~BookShop() {
        for (auto &book : inventory) {
            delete book;
        }
    }
};

int main() {
    BookShop shop;

    // Add some books to the inventory
    shop.addBook("J.K. Rowling", "Harry Potter", 25.5, "Bloomsbury", 10);
    shop.addBook("Dan Brown", "Inferno", 20.0, "Doubleday", 5);
    shop.addBook("George Orwell", "1984", 15.0, "Secker & Warburg", 8);

    cout << "Welcome to the Book Shop Inventory System\n";

    while (true) {
        cout << "\nMenu:\n"
             << "1. Search for a book\n"
             << "2. Exit\n"
             << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string title, author;
            cout << "Enter the book title: ";
            cin.ignore(); // Clear input buffer
            getline(cin, title);
            cout << "Enter the author name: ";
            getline(cin, author);
            shop.searchBook(title, author);
        } else if (choice == 2) {
            cout << "Thank you for using the system!\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
