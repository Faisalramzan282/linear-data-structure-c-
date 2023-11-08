#include <iostream>

struct Node{
    int data;
    Node* next;
    Node(int value): data(value), next(nullptr){}
};
class List
{
private:
    Node* head;
public:
   List(): head(nullptr){}
   void insertAtStart(int value)
   {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
   }
   void insertAtEnd(int value){
    Node* newNode = new Node(value);
    //first we deal of empty list
    if(head==nullptr){
     head = newNode;
    }
    else{
    //and if list is not empty then case
        Node* current = head;
        while(current->next!=nullptr){
        current = current->next;
        }
        current->next = newNode;
    }
   }
   //searchValue method
   bool searchValue(int value){
    if(head == nullptr){
        return false;
    }
    else{
        Node* current = head;
        while(current != nullptr){
           if(current->data == value){
            return true;
           }
           current = current->next;
        }
        return false;
    }
   }
   //delete head node
   void deleteHeadNode(){
    Node* current =  head;
    head = current->next;
    delete current;
   }
   //delete the last node 
   void deleteLastNode(){
    Node* current = head;
    if(current == nullptr){
        std::cout<<"list is empty "<<std::endl;
        return;
    }
    //existing only one element
    if(current->next == nullptr)
    {
        delete current;
        head = nullptr;
    }
    else{
        while(current->next->next != nullptr){
        current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
   }
   void displayAllNodes(){
        Node* current = head;
        while(current!=nullptr){
            std::cout<<current->data<<"->";
            current = current->next;
        }
        std::cout<<"nullptr"<<std::endl;
   }
void deleteNodeWithValue(int value) {
    Node* current = head;
    Node* previous = nullptr;
    if (current == nullptr) {
        std::cout << "Cannot find & delete node element because the list is empty" << std::endl;
        return;
    }
    if (current->data == value) {
        head = current->next;
        delete current;
        return;
    }
    while (current != nullptr) {
        if (current->data == value) {
            previous->next = current->next;
            delete current;
            return; 
        }
        previous = current;
        current = current->next;
    }
}
};
int main(){
    List obj;
    obj.insertAtStart(4);
    obj.insertAtStart(6);
    obj.insertAtStart(8);
    obj.insertAtEnd(5);
    obj.insertAtEnd(10);
    obj.displayAllNodes();
    //now for searching scenario
    int target1 = 5; //existed case
    int target2 = 55; //not existed case
    if(obj.searchValue(target1)){
        std::cout<<target1<<" is existed in the list "<<std::endl;
    }
    else{
        std::cout<<target1 <<" is not existed in the list "<<std::endl;
    }
    if(obj.searchValue(target2)){
        std::cout<<target2<<" is existed in the list "<<std::endl;
    }
    else{
        std::cout<<target2 <<" is not existed in the list "<<std::endl;
    }
    //now deletion case
    obj.deleteHeadNode();
    obj.deleteLastNode();
    obj.deleteNodeWithValue(6);
    obj.displayAllNodes();
    return 0;
}