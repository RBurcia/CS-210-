//Bubble ended in .3222 seconds, .314 seconds, .309.
//Selection ended in .311 seconds, .314, .314




#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> Selection(const vector<int>& values){

    //Seclection sort goes through the vector and chooses a selected element and goes through the vector finding the smallest one to "swap"
    //if going through the array there is a smaller number, it becomes the new "swap" until we reach the end of the array

    //We will need a double for loop, one for the selected element we are in, and another one to search through the array finding the "swap" element
    vector<int> sorted_values = values;
    for(int i = 0; i < sorted_values.size() - 1; ++i){
        int min_Index = i;

        for(int j = i +1 ; j < sorted_values.size()  ; ++j){

            if(sorted_values[min_Index] > sorted_values[j]){
                min_Index = j;
            }
        }
        swap(sorted_values[i], sorted_values[min_Index]);

    }
    return sorted_values;

}

int main(){
    vector<int> vectRand = {29,10,14,37,14,48,10,456,15,10,10,16,1,89,0,10,4,10,74,9,14,9,3,0,1,78,20,13};


    cout << "#### SORTING RANDOM VECTOR ####" << endl;
    vector<int> sorted1 = Selection(vectRand);


    for (int value : sorted1) {
        cout << value << ' ';
    }

    cout << endl;

    cout << "Program ended sorting!" << endl;

}