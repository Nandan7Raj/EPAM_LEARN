//
// Created by NandanRaj on 27-01-2026.
//
#include <iostream>

using namespace std;
struct Point {
    // by default struct members are public
    int x;
    int y;
    // No need of below written setter nad getter to set and get value of variable
    // void setPoints(int x,int y) {
    //     this->x=x;
    //     this->y=y;
    // }
    // void showPoints() {
    //     cout<<"x="<<x<<" y="<<y<<endl;
    // }
};
class Rectangle {
    // by default class members are private
    int lenght;
    int width;
    public:
    // setter and getter functions
    void setDimensions(int l,int w) {
        lenght=l;
        width=w;
    }
    void showDimensions() {
        cout<<"lenght = "<<lenght<<"cm"<<endl;
        cout<<"width = "<<width<<"cm"<<endl;
    }
};
// func to input x and y coordinates
void inputXY(int&x,int&y) {
    while (true) {
        cout<<"Enter Value of X and Y coordinates: ";
        cin>>x>>y;
        if (cin.fail()) {// check for invalid input
            cout<<"Input Error!"<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
        }
        break;// exit loop if input is valid
    }
}
// func to set point
void setPoint(Point* p) {
    int x,y;
    inputXY(x,y);// get x and y values
    //directly assigned value to  variables of structure Point (default public acces).
    p->x=x;
    p->y=y;
    cout<<"value assigned to X and Y coordinates.\n";
}
// func to get point
void getPoint(Point* p) {
    //direct retrival of variables of structure Point due to default public access
    cout<<"Your point is ("<<p->x<<","<<p->y<<")\n";
}
// func to input length and width of rectangle
void inputLenWid(int&len,int&wid) {
    while (true) {
        cout<<"Enter Length and Width of rectangle in cm: ";
        cin>>len>>wid;// take input
        if (cin.fail()) {// check for invalid input
            cout<<"Input Error!"<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
        }
        break;
    }
}
// func to set length and width of rectangle
void set_Length_Widht(Rectangle* r) {
    int len,wid;
    inputLenWid(len,wid);
    // r->length=len ; error as default private access
    // we need to use setter ;
    r->setDimensions(len,wid);
    cout<<"Length and width of rectangle set by using setter function\n";
}
void get_Length_Widht(Rectangle* r) {
    cout<<"Dimension of rectangle :\n";
    r->showDimensions();// using getter to get len and width

}
int main() {
    Point p;// create object of structure Point
    Rectangle r;// create object of class Rectangle
    cout<<"Setting and Getting values of Point structure (with default public access)\n";
    setPoint(&p);// set point
    getPoint(&p);// get point
    cout<<"----------------------------------------\n";
    cout<<"Setting and Getting values of Rectangle class (with default private access)\n";
    set_Length_Widht(&r);// set length and width
    get_Length_Widht(&r);// get length and width
    cout<<"---------------------END----------------------\n";
    return 0;
}