#include <iostream>

/*
Part 1: Build Your Own Linked List
Implement and test a linked list that supports adding, searching, removing, and printing items. Do not use std::list.
 **Made adding the new nodes
 **Printed new nodes
 **Made the remove node


Part 2: Monopoly Game
Use your linked list to build a circular board with at least 10 properties.

Each property stores its name, cost, owner, and next pointer.

Players move around the board, wrapping back to the beginning.

Players can buy unowned properties, but cannot buy owned properties.

Simulate at least 10 turns and print the results 

BONUS POINTS IF YOU CREATE A GUI  😊
Briefly explain the time complexity of adding, searching, removing, moving, and traversing.

*/

using namespace std;

//Creates my linked list with a default head null pointer if empty
struct Node{
    double value;
    Node* next = nullptr;
    Node* previous = nullptr;

    Node(double val) : value(val), next(nullptr){}
};


class linkedlist {
private:
Node* head = nullptr;
Node* tail = nullptr;

public:

    //Make a set function that adds a new node
    double append(double val){
        //Adds a new node to the heap
        Node* newNode = new Node(val);

        //If empty make a the new node as head
        if(head == nullptr){
            head = tail = newNode;
        }
        //Else if not empty, make the new node be sent to the tail
        else{
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }
    //Use this to remove values, will search along the array to do so
    void remove(double val){
        Node* temp = head;
        double tempVal = temp->value;
        bool flag = true;

        //Searches through linked list and flags the while loop to stop when found the tempval
        while(flag){
            if(tempVal != val){
                temp = temp->next;
                flag = false;
            }
            temp = temp->next;
        }
        cout << "removed\n";
    }

    //Use this to search for a value and print it
    void search(double val){
        Node* temp = head;
        double tempVal = temp->value;
        bool flag = true;
        int count = 0;

        //Searches through linked list and flags the while loop to stop when found the tempval
        while(flag){
            cout << count << endl;
            if(tempVal = val){
                count = count + 1;
                cout << "Found value: " << tempVal << " at index: " << count << endl;
                flag = false;
                continue;
            }
            count = count + 1;
            temp = temp->next;
        }
        cout << "Found\n";
    }




    //This is to print out the linkedlist
    void display() const{
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }


};

int main(){
    linkedlist link;
    link.append(10);
    link.append(99.2);
    link.append(15.3);
    link.search(15.3);

    link.display();
    cout << "hello";



    return 0;
}