#include <iostream>
#include <vector>

using namespace std;

// make your vector function called twosum
    vector<int> twoSumBF(const vector<int>& array, int target){
    //Creates my 'neededs' for each index before searching through array
    vector<vector<int>> answers;
    for(int i = 0; i < array.size(); ++i){
        int needed = target - array[i]; // for example 24-15 = 
        //Search through array 
        for(int j = 0; j < array.size(); ++j){
            if(array[j] == needed){
                return {i,j};
            }
        }
    }
    //No target found
    return {};
}

int main(){

    vector<int> nums = {15, 4, 18, 8, 19, 22, 24, 59, 59, 20, 18, 12, 36, 42, 9};
    int target = 24;

    vector<int> answer = twoSumBF(nums, target);

    if(!answer.empty()){
        cout << "Indices: [" << answer[0] << ", " << answer[1] << "]\n";
    }
    else{
        cout << "No solution\n";
    }
}
