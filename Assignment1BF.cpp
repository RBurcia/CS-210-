#include <iostream>
#include <vector>

using namespace std;

// make your vector function called twosum
vector<int> twoSumBF(const vector<int>& array, int target){
    //Creates my 'neededs' for each index before searching through array
    for(int i = 0; i < array.size(); ++i){
        int needed = target - array[i];
        //Search through array 
        for(int j = i+1; j < array.size(); ++j){
            if(array[j] == needed){
                return {i,j};
            }
        }
    }
    //No target found
    return {};
}

int main(){

    vector<int> nums = {3,2,4};
    int target = 6;

    vector<int> answer = twoSumBF(nums, target);

    if(!answer.empty()){
        cout << "Indices: [" << answer[0] << ", " << answer[1] << "]\n";
    }
    else{
        cout << "No solution\n";
    }

    return 0;
}
