#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(const vector<int>& nums, int target){
    unordered_map<int, int> index;

    for(int i = 0; i < nums.size(); ++i){
        int needed = target-nums[i];// 24-15 = 9 which is at index 14

        if(index.count(needed)){
            return{index[needed], i};
        }
        index[nums[i]] = i;
    }
    return {};
}

int main(){
    vector<int> nums = {15, 4, 18, 8, 19, 22, 24, 59, 59, 20, 18, 12, 36, 42, 9};
    int target = 24;

    vector<int> answer = twoSum(nums, target);

    if(!answer.empty()){
        cout << "Indices: [" << answer[0] << ", " << answer[1] << "]\n";
    }
    else{
        cout << "No solution\n";
    }
}