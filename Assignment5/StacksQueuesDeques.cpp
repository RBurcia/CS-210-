#include <iostream>
#include <vector>

using namespace std;


/*
Required implementation:
- Implement a stack using an array-based representation.

- Implement a stack using your own linked-list representation.

- Implement a queue using an array-based representation.

- Implement a queue using your own linked-list representation.

- Implement a deque using an array-based representation.

- Implement a deque using your own linked-list representation.

- For each structure, demonstrate insertion and removal operations, empty handling, and 
  a sequence of at least 10 operations.

- Explain which operations are O(1) and which can become O(n) in your particular design.

- Restrictions: complete the assignment in C++17. Do not use <stack>, <queue>, <deque>, 
  or another container that directly implements the required ADT.
*/

//Setting up Node for my linked list
class ArrayStack{
private:
    int allocationSize;
    int* array;
    int length;
    int maxLength;

    void Resize(){
        int newSize = allocationSize * 2;
        int* newArray = new int[newSize];
        for(int i = 0; i < length; i++){
            newArray[i] = array[i];
        }

        delete[] array;
        array = newArray;
        allocationSize = newSize;
    }



public:
    ArrayStack(int optionalMaxLength = -1){
        allocationSize = -1;
        array = new int[allocationSize];
        length = 0;
        maxLength = optionalMaxLength;
    }

    virtual ~ArrayStack(){
        delete[] array;
    }

    int GetLength() const {
        return length;
    }

    int getMaxLength() const {
        return maxLength;
    }

    bool Push(int item){
        if (length == maxLength){
            return false;
        }
        else if (length == allocationSize){
            Resize();
        }

        array[length] = item;
        length++;
        return true;
    }

    int Pop(){
        if(length == 0){
            cout << "Array stack is empty" << endl;
            return -1;
        }

        int value = array[length - 1];
        array[length - 1] = nullptr;
        length--;

        delete value;
        return value;
        



        //remove last tail element 
        //delete the memory from memory



    }

}
//()()()()()()()()()()()()()() IMPLEMENTING STACK USING ARRAY ()()()()()()()()()()()()()()
// We will treat the back of the array as the top of the stack

//()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()

//()()()()()()()()()()()()() IMPLEMENTING STACK USING LinkedList ()()()()()()()()()()()()()



int main(){

    return 0;
}

