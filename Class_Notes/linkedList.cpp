#include <iostream>
#include <vector>

using namespace std;


// Create your node struct method (Kind of like a default where you dont need any arguments to call on it)
struct Node{
    int value;
    Node* next;
};

int main(){


    Node* first = new Node{10, nullptr};
    Node* second = new Node{15, nullptr};
    Node* third = new Node{30, nullptr};

    first->next = second;
    second->next = third;

    cout<< first->value;

    return 0;
}

