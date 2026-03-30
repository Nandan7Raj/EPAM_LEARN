//
// Created by NandanRaj on 29-03-2026.
//
#include<iostream>
#include <memory>
#include<vector>
class Book {
public:
    std::string title;
    std::string author;

    Book(const std::string& t, const std::string& a) : title(t), author(a) {}
    void print() const {
        std::cout << "Book: " << title << " by " << author << std::endl;
    }
};
class Library {
    std::vector<std::unique_ptr<Book>> books;
public:
    ~Library() {
        // Clean up all books
        std::cout<<"Destructor: deletion will be managed by smart pointer itself\n";
    }
    void addBook(const std::string& title, const std::string& author) {
        books.push_back(std::make_unique<Book>(title,author));
        // books.push_back(new Book(title,author));// as books is vector of unique_ptr<Book>, but not Book
    }

    const Book* findBook(const std::string& title) const {
        for (auto &book : books) {
            if (book->title == title) return book.get();
        }
        return nullptr;
    }
    void removeBook(const std::string& title) {
        for (auto it=books.begin();it != books.end();++it) {
            if ((*it)->title == title) {
                books.erase(it);
                return;
            }
        }
    }

};
int main() {
    Library lib;
    lib.addBook("1984", "George Orwell");
    lib.addBook("Brave New World", "Aldous Huxley");

    // Find a book and keep its pointer
    auto  bookPtr = lib.findBook("1984");
    if (bookPtr) {
        bookPtr->print();
    }

    // Remove the book from the library
    lib.removeBook("1984");
    bookPtr=nullptr;

    // Dangling pointer: bookPtr now points to deleted memory!
    std::cout << "Trying to access deleted book:" << std::endl;
    if (bookPtr) {
        bookPtr->print(); // Undefined behavior!
    }
    return 0;
}