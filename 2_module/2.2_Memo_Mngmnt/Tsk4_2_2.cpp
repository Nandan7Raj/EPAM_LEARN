//
// Created by NandanRaj on 04-02-2026.
//
#include <iostream>
class Item {
    static int count;
    public:
    Item() {
        std::cout<<"A new item obj is created"<<std::endl;
        count++;
    }
    ~Item() {
        std::cout<<"Item obj is deleted"<<std::endl;
        count--;
    }
    static void cur_obj_count() {
        std::cout<<"cur_obj_count is : "<<count<<std::endl;
    }

};
int Item::count=0;

int main(int argc, char *argv[]) {
    // Dynamic Allocation of single Item Obj using new
    Item* Single_obj = new Item{};
    Item::cur_obj_count();
    //Dynamic Allocation of array of Item Obj using new[]
    Item* obj_arr=new Item[5];
    Item::cur_obj_count();
    std::cout<<"\nNow we will do deallocation\n";
    //allocation and deallocation must match
    //new->delete
    // new[]->delete[]
    delete Single_obj;
    // delete[] Single_obj; //--> Undefined behaviour, Assume multiple objects exist
                           //   Try calling destructor multiple times ( program can crash)
    Item::cur_obj_count();
    delete[] obj_arr;
    // delete obj_arr; // --> This is Undefined Behaviour (UB)
                    // program ends here only in my case
    Item::cur_obj_count();
    std::cout<<"Thank you"<< std::endl;




}
