#include <iostream> 



class LinkedList{
public: 
    struct Node{
        int data;
        Node* next;
    };
    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void removeAtBeginning(); 
    void print();  

private:
    Node* head = nullptr; 
};

LinkedList::~LinkedList(){
    Node* curr = head; 
    while(curr != nullptr){
        Node* temp = curr; 
        curr = curr->next; 
        delete temp; 
    }
}

void LinkedList::print(){
    Node* curr = head;
    while(curr != nullptr){
        std::cout << curr->data << " --> ";
        curr = curr->next; 
    }
    std::cout << "NULL";
}

void LinkedList::removeAtBeginning(){
    if(head == nullptr) return; 

    Node* temp = head; 
    head = head->next; 
    delete temp; 
}

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

int main(){

    LinkedList l; 
    l.insertAtBeginning(1);
    l.insertAtBeginning(2);
    l.removeAtBeginning();
    l.insertAtEnd(6);
    l.insertAtBeginning(3);
    l.insertAtEnd(4);
    l.removeAtBeginning();
    l.print(); 

    return 0; 
}