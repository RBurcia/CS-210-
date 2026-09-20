#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Required implementation
Implement bool isSorted(const std::vector<int>& values).

Implement bubble sort, selection sort, insertion sort, and quicksort from scratch.

Verify each algorithm with isSorted after sorting.

Benchmark all four algorithms on random, already sorted, and reverse-sorted input.

Use at least three input sizes. Choose sizes large enough to show a meaningful trend without causing unreasonable run time.

Report a small timing table and explain the observed best, average, and worst behavior.

Restriction: do not use std::sort to perform the required sorts. You may use it only in a separate verification step if you clearly label that use.
*/
vector<int> Bubble(const vector<int>& values){
    bool swapped;
    vector<int> sorted_values = values;

    for(int i = 0; i < sorted_values.size() -1; ++i){

         for(int j = 0; j < sorted_values.size() + i - 1; ++j){

            if(sorted_values[j] > sorted_values[j+1]){

                swap(sorted_values[j], sorted_values[j+1]);
                swapped = true;
            }
        }

        if(!swapped){
            break;
        }
    }
    return sorted_values;
    //for loop around array with a decreasing vector length each loop

    //check index i with index i+1

    //if index i is bigger than index j, swap

    //else continue

    //i++ 

}

vector<int> Selection(const vector<int>& values){

}

vector<int> Insertion(const vector<int>& values){

}

vector<int> quickSort(const vector<int>& values){

}

//Check if my sorted functions worked
bool isSorted(const vector<int>& values){
    bool sorted = true;

    for(int i = 0; i < values.size() - 1; ++i){
        if(values[i] > values[i + 1]){
            return false;
        }
    }
    return true;

}


int main(){
    vector<int> vect1 = {1, 3, 5, 9, 12, 12, 4, 0, 1, 34};
    vector<int> vect2 = {89, 1, 0, 10, 7, 9, 0, 7, 2, 1, 1};

    cout << "Program started!" << endl;
    vector<int> sorted1 = Bubble(vect1);
    bool response = isSorted(sorted1);
    for (int value : sorted1) {
        cout << value << ' ';
    }
    cout << endl;
    cout << response << endl;
    cout << "Program ended!" << endl;



    return 0;
}