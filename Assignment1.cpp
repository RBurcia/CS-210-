#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(const vector<int>& nums, int target){
    unordered_map<int, int> index;

    for(int i = 0; i < nums.size(); ++i){
        int needed = target-nums[i];

        if(index.count(needed)){
            return{index[needed], i};
        }
        index[nums[i]] = i;
    }
    return {};
}

int main(){
    vector<int> nums = {3,2,4};
    int target = 6;

    vector<int> answer = twoSum(nums, target);

    if(!answer.empty()){
        cout << "Indices: [" << answer[0] << ", " << answer[1] << "]\n";
    }
    else{
        cout << "No solution\n";
    }
}