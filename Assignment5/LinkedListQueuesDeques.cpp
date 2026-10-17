#include <iostream>
#include <vector>

using namespace std;


// Create your node struct method (Kind of like a default where you dont need any arguments to call on it)
class LinkedStack{
private:
    struct Node{
        int value;
        Node* next;
        Node(int v, Node* n = nullptr) : value(v), next(n) {}
    };

    Node* head;
    int length;
    int maxLength;
public:
    LinkedStack(int optionalMaxLength = -1):
    head(nullptr),
    length(0),
    maxLength(optionalMaxLength){}

    virtual ~LinkedStack(){
        while (head != nullptr){
            Node* next = head->next;
            delete head;
            head = next;
        }
    }

    int GetLength() const{
        return length;
    }

    bool Queue(int item){
        if (maxLength >= 0 && length >= maxLength){
            return false;
        }

        head = new Node{item, head};
        length++;
        return true;
    }

    int Pop(){
        if (head == nullptr){
            cout << "Linked stack is empty" << endl;
            return -1;
        }

        Node* oldHead = head;
        int value = oldHead->value;
        head = head->next;
        delete oldHead;
        length--;
        return value;
    }

    int peek(){
        if (head == nullptr){
            cout << "Linked stack is empty" << endl;
            return -1;
        }
        cout << "Value peeking is: " ;
        return head->value;
    }

    void print(){
        if(length == 0){
            cout << "Linked stack is empty" << endl;
            return;
        }

        for(Node* cur = head; cur != nullptr; cur = cur->next){
            cout << cur->value << endl;
        }
    }

};

class LinkedQueue{
private:
    struct Node{
        int value;
        Node* next;
        Node(int v, Node* n = nullptr) : value(v), next(n) {}
    };

    Node* head;
    Node* tail;
    int length;
    int maxLength;

public:
    LinkedQueue(int optionalMaxLength = -1):
    head(nullptr),
    tail(nullptr),
    length(0),
    maxLength(optionalMaxLength){}

    virtual ~LinkedQueue(){
        while (head != nullptr){
            Node* next = head->next;
            delete head;
            head = next;
        }
    }

    int GetLength() const{
        return length;
    }

    bool Enqueue(int item){
        if (maxLength >= 0 && length >= maxLength){
            return false;
        }

        Node* node = new Node(item);
        if(tail == nullptr){
            head = tail = node;
        }
        else{
            tail->next = node;
            tail = node;
        }
        length++;
        return true;
    }

    int Dequeue(){
        if (head == nullptr){
            cout << "Linked stack is empty" << endl;
            return -1;
        }

        Node* oldHead = head;
        int value = oldHead->value;
        head = head->next;
        if(head == nullptr){
            tail = nullptr;
        }
        delete oldHead;
        length--;
        return value;
    }

    int peek(){
        if (head == nullptr){
            cout << "Linked stack is empty" << endl;
            return -1;
        }
        cout << "Peeking the queue: ";
        return head->value;
    }

    void print(){
        for(Node* cur = head; cur != nullptr; cur = cur->next){
            cout << cur->value << endl;
        }
    }

};

class LinkedDeque{
private:
    struct Node{
        int value;
        Node* prev;
        Node* next;
        Node(int v) : value(v), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int length;
    int maxLength;

public:
    LinkedDeque(int optionalMaxLength = -1):
    head(nullptr),
    tail(nullptr),
    length(0),
    maxLength(optionalMaxLength){}

    virtual ~LinkedDeque(){
        while (head != nullptr){
            Node* next = head->next;
            delete head;
            head = next;
        }
    }

    int GetLength() const{
        return length;
    }

    bool pushFront(int item){
        if (maxLength >= 0 && length >= maxLength){
            return false;
        }

        Node* node = new Node(item);
        if(head == nullptr){
            head = tail = node;
        }
        else{
            node->next = head;
            head->prev = node;
            head = node;
        }
        length++;
        return true;
    }

    bool pushBack(int item){
        if (maxLength >= 0 && length >= maxLength){
            return false;
        }

        Node* node = new Node(item);

        if(tail == nullptr){
            head = tail = node;
        }
        else{
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        length++;
        return true;
    }

    int popFront(){
        if (head == nullptr){
            cout << "Linked deque is empty" << endl;
            return -1;
        }

        Node* oldhead = head;
        int value = oldhead->value;
        head = head->next;
        
        if(head == nullptr){
            tail = nullptr;
        }
        else{
            head->prev = nullptr;
        }
        delete oldhead;
        length--;
        return value;

    }

    int popBack(){
        if (tail == nullptr){
            cout << "Linked deque is empty" << endl;
            return -1;
        }

        Node* oldtail = tail;
        int value = oldtail->value;
        tail = tail->prev;
        
        if(tail == nullptr){
            head = nullptr;
        }
        else{
            tail->next = nullptr;
        }
        delete oldtail;
        length--;
        return value;
    }

    void print(){
        for(Node* cur = head; cur != nullptr; cur = cur->next){
            cout << cur->value << endl;
        }
    }

};

int main(){

// For linked list
    cout << "Stacking" << endl;
    LinkedStack stack;
    stack.Queue(3);
    stack.Queue(40);
    stack.Pop();
    stack.Queue(1);
    cout<< stack.peek() << endl;
    stack.Queue(56);
    stack.print();
    stack.Pop();
    stack.Pop();
    stack.Queue(1);
    cout << stack.peek() << endl;
    stack.Queue(19);
    stack.Pop();
    stack.print();

    cout << endl;
    cout << "///////////////////////////////" <<  endl;
    cout << endl;

// For linked queue
    cout << "Queueing" << endl;
    LinkedQueue queue;
    queue.Enqueue(1);
    queue.Enqueue(5);
    cout << queue.peek() << endl;
    queue.Enqueue(4);
    queue.Dequeue();
    queue.Dequeue();
    queue.print();
    queue.Enqueue(5);
    queue.Enqueue(23);
    queue.Enqueue(0);
    queue.Enqueue(67);
    queue.print();

    cout << endl;
    cout << "///////////////////////////////" <<  endl;
    cout << endl;

// For linked deque
    cout << "Dequeing" << endl;
    LinkedDeque deque;
    deque.pushFront(1);
    deque.pushFront(5);
    deque.pushFront(4);
    deque.popBack();
    deque.print();
    deque.pushBack(5);
    deque.pushBack(23);
    deque.pushFront(67);
    deque.print();

    cout << endl;
    cout << "///////////////////////////////" <<  endl;
    cout << endl;




    return 0;
}
