//
// Created by NandanRaj on 03-02-2026.
//
#include<iostream>

using namespace std;
class Tracker {
public:
    static int counter;//belongs to class
    Tracker() {
        counter++;
        cout<<"Tracker created | add:"<<this;
        cout<<" | Tracker count after creation= "<<counter<<endl<<endl;
    }
    ~Tracker() {
        counter--;
        cout<<"Tracker deleted | Add: "<<this;
        cout<<" | Tracker count after deletion = "<<counter<<endl<<endl;
    }
     void* operator new(size_t size){
         void *ptr=malloc(size);
        cout << "[ALLOC] Size = " << size
        << " bytes | Address = " << ptr << endl;
         return ptr;
    }
    void operator delete(void *ptr) {
        cout << "[FREE ] Address = " << ptr << endl;
        free(ptr);
    }

};
int Tracker::counter=0;// initializing static variable outside class

int main() {
    cout << "Creating objects\n";
    Tracker* trk1=new Tracker();// obj1 // will allocate memory for obj using new keyword and call constructor to create obj
    Tracker* trk2=new Tracker();//obj2
    Tracker* trk3=new Tracker();//obj3
    delete trk1;// free memory of obj in Trk1 // Will deallocate memory using delete and call destructor
    trk1=nullptr;// saves from dangling pointer
    delete trk2;
    trk2=nullptr;
    // trk3 is not deleted to demonstrate memory leak
    cout<< Tracker::counter<<" object memory leaked"<<endl;
}
