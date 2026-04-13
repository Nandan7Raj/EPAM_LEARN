//
// Created by NandanRaj on 08-04-2026.
//
#include<iostream>
#include <map>
#include<limits>

void clearInputBuffer() {
    std::cin.clear(); // Clear error flags
    // Discard all characters in the input buffer up to the newline character
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool getProductStock(int productId, int& currentStock, const std::map<int, int>& inventoryMap) {
    if (inventoryMap.empty() || inventoryMap.find(productId)==inventoryMap.end()) {
        currentStock=0;
        return false;
    }
    currentStock=inventoryMap.at(productId);
    return true;
}

void displayInventory(const std::map<int, int>& inventoryMap, const std::string& title) {
    std::cout<<"Title: "<<title<<std::endl;
    for (const auto &[key,value]:inventoryMap) {
        std::cout<<"Product ID: "<<key
                 <<" Stock quantity: "<<value<<std::endl;
    }
}

void addNewProduct(std::map<int, int>& inventory) {
    std::cout<<"-------ADDING NEW PRODUCT-------\n";
    int product_id,stock_quantity;
    std::cout<<"Enter Product ID: ";
    std::cin>>product_id;
    if (inventory.count(product_id)>0 ) {
        std::cout<<"Product ID already Exist, perform Restock\n";
        return;
    }
    std::cout<<"Enter Stock Quantity: ";
    std::cin>>stock_quantity;
    if (stock_quantity<0) {
        std::cout<<"Stock quantity can not be negative, perform Restock\n";
        return;
    }
    inventory[product_id]=stock_quantity;
    std::cout<<"New Entry in inventory\n";
}

void performSale(std::map<int, int>& inventory) {
    std::cout<<"------SELLING STOCK-------\n";
    int product_id,stockQntyToSell,avlStock;
    std::cout<<"Enter Product ID: ";
    std::cin>>product_id;
    if (!getProductStock(product_id,avlStock,inventory) ) {
        std::cerr<<"Product ID do not exist\n";
        return;
    }
    std::cout<<"Enter Stock Quantity(positive): ";
    std::cin>>stockQntyToSell;
    if (stockQntyToSell>avlStock) {
        std::cout<<"Insufficient Stock\n";
        return;
    }
    inventory[product_id]-=stockQntyToSell;
    std::cout<<"Sell Successful........\n";
}

void performRestock(std::map<int, int>& inventory) {
    std::cout<<"-----RESTOCKING------\n";
    int product_id,quantity;
    std::cout<<"Enter Product ID: ";
    std::cin>>product_id;
    std::cout<<"Enter Stock Quantity: ";
    std::cin>>quantity;
    if (quantity<0) {
        std::cout<<"Stock quantity can not be negative\n";
        return;
    }
    if (inventory.find(product_id)==inventory.end()) {
        inventory[product_id]=quantity;
    }
    else
        inventory[product_id]+=quantity;

    std::cout<<"Restocking Successful\n";
}

void checkProductStatus(const std::map<int, int>& inventory) {
    std::cout<<"---------CHECKING PRODUCT STATUS---------\n";
    int product_id,curStock;
    std::cout<<"Enter Product ID: ";
    std::cin>>product_id;

    if (!getProductStock(product_id,curStock,inventory) ) {
        std::cout<<"Product ID do not exist\n";
        return;
    }
    std::cout<<"Current stock quantity: "<<curStock<<std::endl;

}

void discontinueProduct(std::map<int, int>& inventory) {
    std::cout<<"--------DISCONTINUE PRODUCT-------\n";
    int productID;
    std::cout<<"Enter Product ID : ";
    std::cin>>productID;
    if(inventory.find(productID)==inventory.end()) {
        std::cout<<"There is no such product ID\n";
        return;
    }
    inventory.erase(productID);
    std::cout<<"DISCONTINUE SUCCESSFUL\n";
}

void ActionToPerform(std::map<int,int>& inventory)
{
    int choice;

    do {
        std::cout << "\n===== Inventory Menu =====\n";
        std::cout << "1. Add New Product\n";
        std::cout << "2. Perform Sale\n";
        std::cout << "3. Perform Restock\n";
        std::cout << "4. Check Product Status\n";
        std::cout << "5. Discontinue Product\n";
        std::cout << "6. Display All Products\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;
        clearInputBuffer();

        switch(choice)
        {
            case 1:
                addNewProduct(inventory);
                break;

            case 2:
                performSale(inventory);
                break;

            case 3:
                performRestock(inventory);
                break;

            case 4:
                checkProductStatus(inventory);
                break;

            case 5:
                discontinueProduct(inventory);
                break;

            case 6:
                displayInventory(inventory, "Current Inventory Overview");
                break;

            case 0:
                std::cout << "Exiting program...\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while(choice != 0);
}

int main(int argc, char *argv[]) {
    std::map<int,int> productInventory;
    productInventory[101] = 50;
    productInventory[102] = 25;
    productInventory[103] = 100;
    productInventory[104] = 10;
    productInventory[105] = 75;

    // Initial inventory display
    displayInventory(productInventory, "Initial Inventory");

    // Start menu
    ActionToPerform(productInventory);

    std::cout << "\nProgram completion\n";


}