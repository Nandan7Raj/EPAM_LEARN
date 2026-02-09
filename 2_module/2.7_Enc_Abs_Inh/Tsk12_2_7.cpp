//
// Created by NandanRaj on 08-02-2026.
//
//
#include<iostream>
#include <vector>

class Item {
    std::string title;
    int id;
public:
    Item():title("Untiteled"),id(0){
        std::cout<<"Item constructor"<<std::endl;
    }
    virtual void display() const=0;
    virtual ~Item() {
        std::cout<<"Item Destructor"<<std::endl;
    }
    bool set_title( const std::string&name) {
        if (name.empty()) {
            std::cout<<"Invalid title(empty)"<<std::endl;
            return false;
        }
            this->title=name;
        return true;

    }
    std::string get_title() const{
        return title;
    }
    bool set_id(int i) {
        if (i <= 0) {
            std::cout << "Invalid id! (must be positive)\n";
            return false;
        }
        id = i;
        return true;
    }
    int get_id() const{
        return id;
    }
};
class Book:public Item {
    int pages;
    public:
    Book():pages(0) {
        //Items have default constructor so no need to call it
        std::cout<<"Book constructor"<<std::endl;
    }
    bool set_pages(int pages) {
        if (pages <= 0) {
            std::cout<<"Invalid pages! (must be positive)\n";
            return false;
        }
        this->pages = pages;
        return true;
    }
    int get_pages() const{
        return pages;
    }
    void display() const override {
        std::cout<<"Book display"<<std::endl;
        std::cout<<"Title : "<<get_title()<<", ID : "<<get_id()<<", Pages : "<<pages<<std::endl;
    }

};
class Magazine :public Item {
    int issue;
public:
    Magazine():issue(0) {
        std::cout<<"Magazine constructor"<<std::endl;
    }
    bool set_issue(int i) {
        if (i <= 0) {
            std::cout<<"Invalid issue! (must be positive)\n";
            return false;
        }
        this->issue = i;
        return true;
    }
    int get_issues() const {
        return issue;
    }
    void display() const override {
        std::cout<<"Magazine display"<<std::endl;
        std::cout<< "Title: " << get_title()
                  << ", ID: " << get_id()
                  << ", Issue: " << issue << "\n";
    }

};

class DVD : public Item {

    double duration; // must be > 0

public:
    DVD() :duration(1.0) {
        std::cout<<"DVD constructor"<<std::endl;
    }

    bool setDuration(double d) {
        if (d <= 0.0) {
            std::cout << "Invalid duration! (must be > 0)\n";
            return false;
        }
        duration = d;
        return true;
    }

    double getDuration() const { return duration; }

    void display() const override {
        std::cout << "[DVD] "
                  << "Title: " << get_title()
                  << ", ID: " << get_id()
                  << ", Duration: " << duration << " mins\n";
    }
};
int main() {
    Item* b= new Book();
    Item* m= new Magazine();
    Item* d= new DVD();
    std::vector<Item*> items;
    items.push_back(b);
    items.push_back(m);
    items.push_back(d);
    // Polymorphic display that shows defaults
    std::cout<<"Library Items"<<std::endl;
    for (const Item* i:items) {
        i->display();
    }
    // Now Encapsulation + Validation Demo
    std::cout<<"Setting invalid data"<< std::endl;
    //Base-class validation
    b->set_title("");
    m->set_id(-10);

    //Derived class validation ( and we need pointer of derived class to get setter and getter of derived class)
    Book* b_ptr=dynamic_cast<Book*>(b);
    b_ptr->set_pages(-3);

    Magazine* m_ptr=dynamic_cast<Magazine *>(m);
    m_ptr->set_issue(-23);

    DVD* d_ptr=dynamic_cast<DVD*>(d);
    d_ptr->setDuration(-76);

    std::cout << "\n---- After Invalid Attempts (Objects Still Valid) ----\n";
    for (const Item* it : items) {
        it->display();
    }
    // free memory
    for (const Item* it : items) {
        delete it;
        it=nullptr;
    }



}