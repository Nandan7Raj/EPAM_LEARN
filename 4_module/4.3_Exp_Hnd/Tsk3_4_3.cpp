//
// Created by NandanRaj on 20-02-2026.
//
#include<iostream>
#include<stdexcept>
#include<limits>
#include <utility>
#include<vector>
#include<string>
#include<cmath>
#include <iomanip>

class InvalidPriceException:public std::runtime_error {
    std::string msg;
public:
    explicit InvalidPriceException(const char* msg):msg(msg),std::runtime_error(msg) {}
    explicit InvalidPriceException(const std::string&msg):std::runtime_error(msg),msg(msg){}
};
class Product {
    std::string name;
    double price;
    int stock;
public:
    explicit Product(std::string name,const double& price,const int&stock):
    name(std::move(name)),price(price),stock(stock){}

    [[nodiscard]] std::string get_name() const {
        return name;
    }

    [[nodiscard]] double get_price() const {
        return price;
    }

    [[nodiscard]] int get_stock() const {
        return stock;
    }
    void set_price(const double& p) {
        price=p;
    }
    void display() const{
        std::cout<<"product details :\n"
        <<"Name: "<<name<<"\n"
        <<"Price: "<<std::fixed<<std::setprecision(2)<<price<<"\n"
        <<"Stock: "<<stock<<"\n";
    }
};

bool checkDecimalPoint(const double& price) {
    double temp=price*100;
    int int_temp=(int)temp;
    return (temp-int_temp!=0.0);
}

double getNewPrice() {
    double price;
    std::cout<<"Enter new price:";
    std::cin>>price;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        throw InvalidPriceException("Error: Invalid product selection.");
    }
    if ((price<0) || (price>10000)) {
        throw InvalidPriceException("Error: Invalid product selection.");
    }
    if (checkDecimalPoint(price)) {
        throw InvalidPriceException("Error: Invalid product selection.");
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return price;
}

void updateProductPrice(Product& product) {
    product.display();

    double price;
    while (true) {
        try {
            price = getNewPrice();
            break;
        }
        catch (const InvalidPriceException& e) {
            std::cout<<e.what()<<std::endl;
        }
        catch (...) {
            std::cout<<"Unknown Exception"<<std::endl;
        }
    }
    if (price>(1.5*product.get_price())){
      throw  InvalidPriceException("Error: Price change cannot exceed 50% in single update.");
    }
    product.set_price(price);
    std::cout<<"Update of price Successful"<< std::endl;

}

void displayInventory(const Product product_arr[],const int n) {

    for (int i=0;i<n;i++){
        std::cout<<"Displaying product "<<i+1<<"\n";
        product_arr[i].display();
    }
}
int main() {
    std::cout<<"Welcome\n";
    Product product_arr[]{Product{"Product1",23.43,2},Product{"Product2",
        34.43,5},Product{"Product3",53,1}};
    for (auto & i : product_arr) {
        updateProductPrice(i);
    }
    displayInventory(product_arr,3);
    int product_no,exit=0;
    while (exit==0) {
        std::cout<<"Enter product no to update price of it:";
        std::cin>>product_no;
        updateProductPrice(product_arr[product_no]);
        std::cout<<"Enter 1 to exit else 0 to continue:";
        std::cin>>exit;
    }
    displayInventory(product_arr,3);

}

