#include <iostream>
struct Node
{
    Node *prev;
    Node *next;
    int data;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};
class List
{
private:
    Node *head;
    Node *tail;

public:
    List() : head(nullptr), tail(nullptr) {}
    void insertAtStart(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void displayAllNodes()
    {
        if (head == nullptr)
        {
            std::cout << "List is empty " << std::endl;
        }
        else
        {
            Node *current = head;
            while (current != nullptr)
            {
                std::cout << current->data << "<->";
                current = current->next;
            }
            std::cout << "nullptr" << std::endl;
        }
    }
    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            // Case of an empty list
            head = newNode;
            tail = newNode;
        }
        else
        {
            // Append the new node to the end of the list
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void insertAtMiddle(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            Node *fast = head;
            Node *slow = head;
            while (fast != nullptr && fast->next != nullptr)
            {
                fast = fast->next;
                if (fast->next != nullptr)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
            }
            // now we find the middle node at the form of slow pointer
            newNode->next = slow->next;
            if (slow->next != nullptr)
            {
                slow->next->prev = newNode;
            }
            slow->next = newNode;
            newNode->prev = slow;
        }
    }
    void deleteAtMiddle()
    {
        if (head == nullptr)
        {
            std::cout << "list is empty" << std::endl;
        }
        else
        {
            Node *fast = head;
            Node *slow = head;
            while (fast != nullptr && fast->next != nullptr)
            {
                fast = fast->next;
                if (fast != nullptr)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
            }
            // now we have slow pointer at the middle of the node
            // if we have only one node
            if (fast == slow)
            {
                head = nullptr;
                tail = nullptr;
                delete fast;
                return;
            }
            // atleast two nodes
            if (slow->next == nullptr)
            {
                slow->prev->next = nullptr;
            }
            if (slow->next != nullptr)
            {
                slow->prev->next = slow->next;
            }
            delete slow;
            // return;
        }
    }
    void deleteWithValue(int value)
    {
        if (head == nullptr)
        {
            std::cout << "List is empty" << std::endl;
            return;
        }
        else
        {
            Node *current = head;
            //  std::cout<<"inside else con"<<std::endl;
            while (current != nullptr)
            {
                //check if the list has only one element and matched
                if (current==head && current->data == value && current->next == nullptr) {
                delete current;
                head = nullptr;
                tail = nullptr;
                return;
                }
                //check if current is first node and it has further ahead nodes
                if(current == head && current->data == value && current->next != nullptr)
                {
                    Node* temp = current;
                    head = temp->next;
                    delete temp;
                    head->prev = nullptr;
                    current = head;
                }
                //check if last node is matched 
                if(current == tail && current != head && current->data == value && current->next == nullptr){
                tail = tail->prev;
                tail->next = nullptr;
                delete current;
                current = tail;
                }
                // Check if the element is found in other nodes, means in between of middle nodes
                if (current->data == value && current->next != nullptr) {
                std::cout<<"Matched condition is "<<std::endl;
                Node* temp = current->prev;
                current->prev->next = current->next;
                delete current;
                current = temp;
                std::cout<<"now current is "<<current->data<<std::endl;
                std::cout<<"current->next"<<current->next->data<<std::endl;
                }
                current = current->next;
            }
        }
    }
    bool checkCircular() {
    if (!head) {
        std::cout << "List is empty" << std::endl;
        return false;
    } else {
        Node* fast = head;
        Node* slow = head;

        while (fast != nullptr) {
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
int main()
{
    List obj;
    obj.insertAtStart(12);
    obj.insertAtStart(3);
    obj.insertAtEnd(122);
    obj.insertAtEnd(144);
    obj.insertAtMiddle(23);
    // before deletion  view of all elements
    obj.displayAllNodes();
    //  obj.deleteAtMiddle();
    obj.deleteWithValue(144);
    obj.displayAllNodes();
    if(obj.checkCircular()){
        std::cout<<"list is circular"<<std::endl;
    }else{
        std::cout<<"list is not circular "<<std::endl;
    }
    return 0;
}