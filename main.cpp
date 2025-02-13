#include <iostream> 



class LinkedList{
public: 
    struct Node{
        int data;
        Node* next;
    };
    void insertAtBeginning(int data);
    void insertAtEnd(int data); 
    void print(); 

private:
    Node* head = nullptr; 
};



void LinkedList::insertAtEnd(int data){
    if(head == nullptr){
        insertAtBeginning(data);
        return; 
    }

    Node* curr = head; 

    while(curr->next != nullptr){
        curr = curr->next; 
    }

    curr->next = new Node{data, nullptr};
}



void LinkedList::insertAtBeginning(int data){
    head = new Node{data, head};
}

void LinkedList::print(){
    //stub 
}

int main(){

    LinkedList l; 
    l.insertAtBeginning(1);
    l.insertAtBeginning(2);
    l.insertAtEnd(6);
    l.insertAtBeginning(3);
    l.insertAtEnd(4);

    //Should Print {3} -> {1} -> {2} -> {6} -> {4} -> NULL
    l.print(); 

    return 0; 
}