#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
    void setDetails(const string& t, const string& a, int y) {
        title = t;
        author = a;
        year = y;
    }

    void display() const {
        cout << "\nTitle: " << title << "\nAuthor: " << author << "\nYear: " << year << endl;
    }

    string getTitle() const { return title; }
};

class Library {
private:
    Book books[10];
    int count = 0;

public:
    void addBook(const Book& b) {
        if (count < 10) {
            books[count++] = b;
            cout << "Book added.\n";
        } else {
            cout << "Library is full.\n";
        }
    }

    void displayAllBooks() const {
        if (count == 0) {
            cout << "No books available.\n";
            return;
        }
        for (int i = 0; i < count; ++i) {
            books[i].display();
            cout << "---------------------\n";
        }
    }

    void searchBookByTitle(const string& title) const {
        for (int i = 0; i < count; ++i) {
            if (books[i].getTitle() == title) {
                cout << "Book found:\n";
                books[i].display();
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

void addBook(Library& lib) {
    string title, author;
    int year;

    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter year: ";
    while (!(cin >> year)) {
        cout << "Invalid year. Enter again: ";
        cin.clear();
        cin.ignore();
    }

    Book newBook;
    newBook.setDetails(title, author, year);
    lib.addBook(newBook);
}

int main() {
    Library library;
    int choice;
    string searchTitle;

    cout << "Library Assistant\n";
    do {
        cout << "\n1. Add a book\n2. Display all books\n3. Search for a book\n4. Exit\nChoose (1-4): ";
        while (!(cin >> choice) || choice < 1 || choice > 4) {
            cout << "Invalid choice. Try again: ";
            cin.clear();
            cin.ignore();
        }

        switch (choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                library.displayAllBooks();
                break;
            case 3:
                cout << "Enter book title to search: ";
                cin.ignore();
                getline(cin, searchTitle);
                library.searchBookByTitle(searchTitle);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
