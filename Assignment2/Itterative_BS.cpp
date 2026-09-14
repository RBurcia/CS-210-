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
            compare_I++;
            low = mid + 1;
        }

        //checks left side
        else if(array[mid] > target){
            compare_I++;
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
    return -1;
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
    int low = 0;
    int array[] = { 2, 4, 7, 9, 10, 11, 32, 45, 87 };
    int high = (sizeof(array) / sizeof(array[0])) - 1;

    // Test to be made:
    //first element **
    //last element 
    //middle element
    //missing element
    //missing value outside of range

/////////////////////////////Test for itterative/////////////////////////////
    cout << "Starting testing for Iterative Binary Search" << endl << endl;

//&&&&&&&&&&&&&&  Testing first element   &&&&&&&&&&&&&&
    int comparisons = 0;
    int key_first = 2;
    int Test_First_I = Itterative_BS(array, high, key_first, comparisons);

    cout << "key_first at Index: " << Test_First_I << " and required " << comparisons << " comparisons" << endl;

//&&&&&&&&&&&&&&  Testing last element   &&&&&&&&&&&&&&
    comparisons = 0;
    int key_last = 87;
    int Test_Last_I = Itterative_BS(array, high, key_last, comparisons);

    cout << "key_last at Index: " << Test_Last_I << " and required " << comparisons << " comparisons" << endl;

//&&&&&&&&&&&&&&  Testing middle element   &&&&&&&&&&&&&&
    comparisons = 0;
    int key_middle = 10;
    int Test_Middle_I = Itterative_BS(array, high, key_middle, comparisons);

    cout << "key_middle at Index: " << Test_Middle_I << " and required " << comparisons << " comparisons" << endl;


//&&&&&&&&&&&&&&  Testing missing element   &&&&&&&&&&&&&&
    comparisons = 0;
    int key_missing = 1;
    int Test_Missing_I = Itterative_BS(array, high, key_missing, comparisons);

    cout << "key_missing at Index: " << Test_Missing_I << " and required " << comparisons << " comparisons" << endl;



//&&&&&&&&&&&&&&  Testing missing value outside of range   &&&&&&&&&&&&&&
//Hint: we can just copy lat element testing and plug a high that is not the max length
    comparisons = 0;
    int high_not = (sizeof(array) / sizeof(array[0]))-2;
    int key_hidden = 87;
    int Test_Hidden_I = Itterative_BS(array, high_not, key_hidden, comparisons);

    cout << "key_hidden at Index: " << Test_Hidden_I << " and required " << comparisons << " comparisons" << endl << endl;





/////////////////////////////Test for recursive/////////////////////////////
    cout << "Starting testing for Recurcsive Binary Search" << endl << endl;

//&&&&&&&&&&&&&&  Testing first element   &&&&&&&&&&&&&&
    comparisons = 0;
    int key2_first = 2;
    int Test2_First_I = Recursive_BS(array, low, high, key2_first, comparisons);

    cout << "key_first at Index: " << Test2_First_I << " and required " << comparisons << " comparisons" << endl;

//&&&&&&&&&&&&&&  Testing last element   &&&&&&&&&&&&&&
    comparisons = 0;
    int key2_last = 87;
    int Test2_Last_I = Recursive_BS(array, low, high, key2_last, comparisons);

    cout << "key_last at Index: " << Test2_Last_I << " and required " << comparisons << " comparisons" << endl;

//&&&&&&&&&&&&&&  Testing middle element   &&&&&&&&&&&&&&
    comparisons = 0;
    int key2_middle = 10;
    int Test2_Middle_I = Recursive_BS(array, low, high, key2_middle, comparisons);

    cout << "key_middle at Index: " << Test2_Middle_I << " and required " << comparisons << " comparisons" << endl;


//&&&&&&&&&&&&&&  Testing missing element   &&&&&&&&&&&&&&
    comparisons = 0;
    int key2_missing = 1;
    int Test2_Missing_I = Recursive_BS(array, low, high, key2_missing, comparisons);

    cout << "key_missing at Index: " << Test2_Missing_I << " and required " << comparisons << " comparisons" << endl;



//&&&&&&&&&&&&&&  Testing missing value outside of range   &&&&&&&&&&&&&&
//Hint: we can just copy lat element testing and plug a high that is not the max length
    comparisons = 0;
    int high2_not = (sizeof(array) / sizeof(array[0]))-2;
    int key2_hidden = 87;
    int Test2_Hidden_I = Recursive_BS(array, low, high2_not, key2_hidden, comparisons);

    cout << "key_hidden at Index: " << Test2_Hidden_I << " and required " << comparisons << " comparisons" << endl;


////&&&&&&&&&&&&&&  Technical explanation:  &&&&&&&&&&&&&& 

// Explain your design decisions, tests, results, and time/space complexity where applicable.

//    My design choice for the iterative binary search was to implement it in a while loop. Inside 
//the while loop, I have two if statements that check both the left and right sides of the array; if
// the target is on the left side, we set high to the middle value minus 1. We keep doing this iteratively
// until the target value is found, all while keeping count of each comparison. For the recursive binary search,
// we treat our left and right checks as the base cases for which the function is called each time.

//    The tests were done as expected; I just changed the key while keeping the same array to test whether the
// target is in the middle, end, beginning, not in the array, and outside of the array.

//    The results were as expected; they both share the same index where the key was found, but the iterative 
//searches had the most comparisons to be made during the search.

//    The time complexity of the iterative search was O(logn), and the space complexity was O(1) since we keep
// the same memory of the array. The time complexity of the recursive search was O(logn), and the space complexity is also O(logn) since for each recursion we create a new pointer to the same array but half of it. We keep doing this repetition until we find the target.

//    Why we have the T(n) = T(n/2) + O(1) refer to the same thing as O(log n) for the recursive search, is 
//because one time doing a loop in a recursion can be referred to as the same thing as T(n/2) + O(1), where 
//O(1) refers to the first comparison in the middle of the array and T(n/2) refers to us going into the recursive
// function again, but taking half of the array instead. When we have big arrays we exponentially get closer to the
// target by taking half of the array each time, but instead of being slow regardless how exponentially bigger
// our input is, it becomes fast regardless of how exponentially big our input size is.

    

    return 0;
}