#include <iostream>

class Stack{
public:
    int* arr;
    int top;
    int capacity;
    Stack(){
        //first create 10 elements and it is resizeable also 
        arr = new int[10];
        capacity = 10;
        top = -1;
    }
    void push(int value){
       if(top == capacity-1){
        int newCapacity = capacity+10;
        int* newArray = new int[newCapacity];
        for(int i =0 ; i<capacity; i++){
            newArray[i] = arr[i];
        }
        delete [] arr;
        arr = newArray;
        capacity = newCapacity;
       }
    top++;
    arr[top] = value;
    }
    void showStack(){
     if(top==-1){
        std::cout<<"Stack is empty "<<std::endl;
     }
     else{
        for(int i =0; i<=top; i++){
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
     }
    }
    void pop(){
        if(top==-1){
            std::cout<<"stack is empty so pop operation does not work "<<std::endl;
        }
        else{
        top--;
        // std::cout << "Top is " << top << std::endl;
        // std::cout << "Capacity before if " << capacity << std::endl;
        if (capacity >= 10 && (capacity - (top+1) == 10)) {
            capacity = capacity - 10;
            int* newArray = new int[capacity];
            for (int i = 0; i <= top; i++) {
                newArray[i] = arr[i];
            }
            delete[] arr;
            arr = newArray;        
    }
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(capacity == top+1){
            return true;
        }
        return  false;
    }
};
int main(){
    Stack obj;
    obj.push(12);
    obj.push(15);
    obj.push(23);
    obj.push(12);
    obj.push(15);
    obj.push(23);
    obj.push(12);
    obj.push(15);
    obj.push(23);
    obj.push(12);
    obj.push(15); 
    obj.push(12);
    obj.push(15);
    obj.push(23);
    obj.push(12);
    obj.push(15);
    obj.push(23);
    obj.push(12);
    obj.push(15);
    obj.push(23);
    obj.push(12);
    // obj.push(15);
    // obj.push(111);
    std::cout<<"Before pop"<<std::endl;
    obj.showStack();
    obj.pop();
    obj.pop();
    obj.pop();
    std::cout<<"after pop"<<std::endl;
    obj.showStack();
    if(obj.isEmpty()){
    std::cout<<"stack is Empty"<<std::endl;
    }
    else{
        std::cout<<"Stack has elements"<<std::endl;
    }
    //check whether stack is full or not 
    if(obj.isFull()){
        std::cout<<"stack is full "<<std::endl;
    }else{
        std::cout<<"stack contain space "<<std::endl;
    }
    return 0;
}