#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int Itterative_BS(const int* array, int high, int target, int& compare_I){
    int low = 0;
    
    //make it check mid and then check left or right
    while(high >= low){
        int mid = (high + low)/2;

        // checks right side
        if(array[mid] < target){
            low = mid + 1;
        }

        //checks left side
        else if(array[mid] > target){
            high = mid - 1;
        }

        //Answere
        else{
            compare_I++;
            return mid;
        }
        //add on to the number of comparisons
        compare_I++;
    }
}

int Recursive_BS(const int* array, int low, int high, int target, int& compare_R){
    //if our we have no array or if array sizes make no sense
    if(low > high){
        return -1;
    }

    int mid = (low + high)/ 2;

    //checks left
    if( target < array[mid]){
        compare_R++;
        return Recursive_BS(array, low, mid - 1, target, compare_R);
    }
    //checks right
    else if( array[mid] < target){
        compare_R++;
        return Recursive_BS(array, mid + 1, high, target, compare_R);
    }
    //adds to the numeber of comparisons and return answer
    compare_R++;
    return mid;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
    int comparisons = 0;
    int low = 0;
    int array[] = { 2, 4, 7, 10, 11, 32, 45, 87 };
    int key2 = 0;
    int high = sizeof(array) / sizeof(array[0]);

    // Test to be made:
    //first element **
    //last element 
    //middle element
    //missing element
    //missing value outside of range

/////////////////////////////Test for itterative/////////////////////////////
//&&&&&&&&&&&&&&  Testing first element   &&&&&&&&&&&&&&
    int key_first = 2;

    int Test_first_I = Itterative_BS(array, high, key_first, comparisons);
    cout << "Key at Index: " << Test_first_I << " and required " << comparisons << " comparisons" << endl;

//&&&&&&&&&&&&&&  Testing last element   &&&&&&&&&&&&&&

    int Test_Last_I = Itterative_BS(array, high, key2, comparisons);

    cout << "Key at Index: " << Test_Last_I << " and required " << comparisons << " comparisons" << endl;

//&&&&&&&&&&&&&&  Testing middle element   &&&&&&&&&&&&&&



//&&&&&&&&&&&&&&  Testing missing element   &&&&&&&&&&&&&&



//&&&&&&&&&&&&&&  Testing missing value outside of range   &&&&&&&&&&&&&&
//Hint: we can just copy lat element testing and plug a high that is not the max length





/////////////////////////////Test for recursive/////////////////////////////
    cout << "Testing for recursive" << endl;

    int Test_R = Recursive_BS(array, low, high, key_first, comparisons);
    cout << "Key for recurssion at Index: " << Test_R << " and required " << comparisons << " comparisons" << endl;
    

    return 0;
}