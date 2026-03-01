//
// Created by NandanRaj on 17-02-2026.
//
#include <iostream>
#include <memory>

class Node {
    int value;
    std::unique_ptr<Node> next;
    Node(int v):value(v), next(nullptr){}
    friend class LinkedList;
};
class LinkedList {
std::unique_ptr<Node> head;
public:
    void push_front(int x) {
        std::unique_ptr<Node> nw_Nod(new Node(x));// possible as friend class
        // make_unique<Node>(x) fails as make_unique → calls new Node(...)
        //but that call happens inside the make_unique function, not inside LinkedList.

        nw_Nod->next=std::move(head);//unique_ptr cannot be copied,it can only be moved
        head=std::move(nw_Nod);
    }
    void printLL() {
        auto temp=head.get();// non-owning raw pointer for traversal
        while (temp) {
            std::cout<<temp->value<<" ";
            temp=temp->next.get();
        }
    }
};
int main() {
    //Node n(3);// not possible as private constructor
    LinkedList ll;
    int x=8;
    ll.push_front(x);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_front(40);
    ll.push_front(50);
    ll.printLL();
}