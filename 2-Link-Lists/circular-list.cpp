#include <iostream>

struct Node{
 public:
    int data;
    Node* next;
    Node(int value) : data(value){}
};
class CircularList{
  public:
  Node* head;
  CircularList() : head(nullptr){}
void insertAtStart(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        newNode->next = head; 
    } else {
        newNode->next = head;
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode; 
        head = newNode; 
    }
}
void insertAtEnd(int value){
  Node* newNode = new Node(value);
  if(!head){
   head = newNode;
   newNode->next = head;
  }
  else{
  Node* current = head;
  while(current->next!=head){
    current = current->next;
  }
  current->next = newNode;
  newNode->next = head;
  }
}
  void displayAllNodes() {

    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
    } 
    else {
        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }
}
bool checkCircular() {
    if (!head) {
        std::cout << "List is empty" << std::endl;
        return false;
    } else {
        Node* fast = head;
        Node* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
}

};
int main(){
   CircularList obj;
   obj.insertAtStart(123);
   obj.insertAtStart(166);
   obj.insertAtEnd(10);
   obj.displayAllNodes();
   if(obj.checkCircular()){
    std::cout<<"list is circular"<<std::endl;
   }else{
    std::cout<<"list is not circular"<<std::endl;
   }
}