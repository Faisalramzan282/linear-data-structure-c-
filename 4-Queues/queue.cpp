#include <iostream>
//Queues implementations using queues 
struct Node
{
    public:
          int data;
          Node* next;
    Node(int value): data(value), next(nullptr){}
};
class Queue{
   public:
   Node* front;
   Node* rear;
   Queue(){
    front = nullptr;
    rear = nullptr;
   }
   int isEmpty(){
    if(front == nullptr){
        return true;
    }
    return false;
   }
   void enqueue(int value){
   //enqueu with rear side but dequeue is front side 
    Node* newNode =new Node(value);
    if(isEmpty()){
        front= newNode;
        rear = newNode;
        newNode->next = nullptr;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
   }
   void dequeue(){
   if(isEmpty()){
    std::cout<<"stack is empty so did not dequeue"<<std::endl;
   }
   if(front==rear){
    front = rear = nullptr;
   }
   else{
      Node* temp = front;
      front = front->next ;
      delete temp;
   }
   }
   void display(){
     Node* current = front;
     if(current == nullptr){
        std::cout<<"Queue is empty"<<std::endl;
     }
     else{
     while(current!=nullptr){
      std::cout<<current->data<<"->";
      current = current->next;
     }
     std::cout<<"nullptr"<<std::endl;
    }
   }
   int peek(){
    if(isEmpty()){
     return -1;
    }
    return rear->data;
   }
};
int main(){
    Queue obj;
    obj.enqueue(12);
    obj.enqueue(14);
    obj.enqueue(34);
    obj.display();
    obj.dequeue();
    obj.display();
    std::cout<<"Peek/top value is "<<obj.peek()<<std::endl;
    return 0;
}
