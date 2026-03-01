//
// Created by NandanRaj on 15-02-2026.
//
#include<iostream>
#include<string>
#include<fstream>
#include <limits>
#include <utility>
class Book {
    std::string title;
    std::string auther;
    double price;
    public:
    Book(std::string title,std::string auther,double price):
    title(std::move(title)),auther(std::move(auther)),price(price){}
    void print_data() const {
        std::cout<<"Title : "<<title<<std::endl;
        std::cout<<"Auther : "<<auther<<std::endl;
        std::cout<<"Price : "<<price<<std::endl;
    }
    friend void saveToFile(const Book& book, std::ofstream& ofs);
    friend Book loadFromFile(std::ifstream& ifs);
};
void saveToFile(const Book& book, std::ofstream& ofs) {
    ofs<<book.title<<'\n'<<book.auther<<'\n';
    ofs<<book.price<<'\n';
}
Book loadFromFile(std::ifstream& ifs) {

    std::string title;
    std::string auther;
    double price;
        if (!std::getline(ifs>>std::ws,title)) {
            std::cerr << "End of file reached or some error happend" << std::endl;
        }

        std::getline(ifs>>std::ws,auther);
        ifs>>price;
        ifs.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        Book book{title,auther,price};
    return book;
}
int main() {
    std::ofstream out("book.txt" ,std::ios::app);
    if (!out) {
        std::cerr<<"Unable to open file for writing"<<std::endl;
        return 1;
    }
    int no_of_books;
    std::cout<<"Enter no of books: ";
    std::cin>>no_of_books;
    std::string title;
    std::string auther;
    double price;
    for(int i=0;i<no_of_books;i++) {
        std::cout<<"Enter title: ";
        std::getline(std::cin>>std::ws,title);
        std::cout<<"Enter auther: ";
        std::getline(std::cin>>std::ws,auther);
        std::cout<<"Enter price: ";
        std::cin>>price;
        // Book* book=new Book{title,auther,price};
        Book book{title,auther,price};// same add
        std::cout<<"Add: "<<&book<<std::endl;
        // saving to file
        saveToFile(book,out);
        // delete book;
    }
    out.close();
    std::ifstream in("book.txt");
    if (!in) {
        std::cerr<<"Unable to open file for reading"<<std::endl;
        return 1;
    }
    int i=0;
    while (true) {
        Book b=loadFromFile(in);
        if (!in)
            break;
        std::cout<<"Info of Book "<<++i<<std::endl;
        b.print_data();
    }

}