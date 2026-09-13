#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int Itterative_BS(const int* array, int high, int target, int& compare_I){
    int low = 0;
    
    //make it check mid and then check left or right
    while(high >= low){
        int mid = (high + low)/2;


        if(array[mid] < target){
            low = mid + 1;
        }

        else if(array[mid] > target){
            high = mid - 1;
        }
        else{
            compare_I++;
            return mid;
        }
        compare_I++;
    }
}

int Recursive_BS(const int* array, int low, int high, int target, int& compare_R){
    if(low > high){
        return -1;
    }

    int mid = (low + high)/ 2;

    if( target < array[mid]){
        compare_R++;
        return Recursive_BS(array, low, mid - 1, target, compare_R);
    }
    else if( array[mid] < target){
        compare_R++;
        return Recursive_BS(array, mid + 1, high, target, compare_R);
    }

    compare_R++;
    return mid;
}


int main(){
    int comparisons = 0;
    int low = 0;
    //Test for iterative
    int numbers[] = { 2, 4, 7, 10, 11, 32, 45, 87 };
    int key = 7;
    int key2 = 0;
    int high = sizeof(numbers) / sizeof(numbers[0]);


    int Test_I = Itterative_BS(numbers, high, key, comparisons);
    cout << "Key at Index: " << Test_I << " and required " << comparisons << " comparisons" << endl;

    int Test_I2 = Itterative_BS(numbers, high, key2, comparisons);

    cout << "Key at Index: " << Test_I << " and required " << comparisons << " comparisons" << endl;

    //Test for recursive
    cout << "Testing for recursive" << endl;

    int Test_R = Recursive_BS(numbers, low, high, key, comparisons);
    cout << "Key for recurssion at Index: " << Test_R << " and required " << comparisons << " comparisons" << endl;
    

    return 0;
}