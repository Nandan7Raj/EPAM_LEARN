//
// Created by NandanRaj on 14-02-2026.
//
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Book {
    std::string title;
    std::string auther;
    double price;
    public:
    friend std::istream& operator>>(std::istream& in,Book& book);
    friend std::ostream& operator<<(std::ostream& out,const Book& book);

};
std::istream& operator>>(std::istream & in, Book& book) {
    std::cout<<"Enter title: ";
    std::getline(in>>std::ws,book.title);
    std::cout<<"Enter auther: ";
    std::getline(in>>std::ws,book.auther);
    std::cout<<"Enter price: ";
    in>>book.price;
    return in;
}
std::ostream& operator<<(std::ostream& out, const Book& book) {
    out<<"Book Title: "<<book.title<<"\n";
    out<<"Book Auther: "<<book.auther<<"\n";
    out<<"Book Price: "<<book.price;
    return out;
}
int main() {
    int no_of_book;
    std::cout<<"Enter the number of books: ";
    std::cin>>no_of_book;
    if (std::cin.fail()) {
        std::cerr<<"Invalid number of books\n";
        return 1;
    }
    std::vector<Book> books(no_of_book);
    for (auto &b:books) {
        std::cin>>b;
    }
    for (auto &b:books) {
        std::cout<<b<<std::endl;
    }
}