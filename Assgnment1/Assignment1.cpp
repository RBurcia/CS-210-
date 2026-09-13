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

    cout << "First normal input\n";

    vector<int> nums = {15, 4, 18, 8, 19, 22, 24, 59, 59, 20, 18, 12, 36, 42, 9};
    int target = 24;

    vector<int> answer = twoSum(nums, target);

    if(!answer.empty()){
        cout << "Indices: [" << answer[0] << ", " << answer[1] << "]\n";
    }
    else{
        cout << "No solution\n";
    }

    ////////////////////////////////////////////////////////////////////////////////////

    cout << "Test Case #1 \n";

    vector<int> nums1 = {5, 5, 10, 4, 2, 8};
    int target1 = 10;

    vector<int> answer1 = twoSum(nums1, target1);

    if(!answer1.empty()){
        cout << "Indices: [" << answer1[0] << ", " << answer1[1] << "]\n";
    }
    else{
        cout << "No solution\n";
    }

    ////////////////////////////////////////////////////////////////////////////////////

    cout << "Test Case #2 \n";

    vector<int> nums2 = {4, 2, 1, 19, 8, 10};
    int target2 = 0;

    vector<int> answer2 = twoSum(nums2, target2);

    if(!answer2.empty()){
        cout << "Indices: [" << answer2[0] << ", " << answer2[1] << "]\n";
    }
    else{
        cout << "No solution\n";
    }

    ////////////////////////////////////////////////////////////////////////////////////

    cout << "Test Case #3 \n";

    vector<int> nums3 = {8, 20, 16, 100, 8, 4};
    int target3 = 24;

    vector<int> answer3 = twoSum(nums3, target3);

    if(!answer3.empty()){
        cout << "Indices: [" << answer3[0] << ", " << answer3[1] << "]\n";
    }
    else{
        cout << "No solution\n";
    }

    ////////////////////////////////////////////////////////////////////////////////////

    cout << "Test Case #4 \n";

    vector<int> nums4 = {3, 10, 9, 0, 10, 6, 1, 8};
    int target4 = 9;

    vector<int> answer4 = twoSum(nums4, target4);

    if(!answer4.empty()){
        cout << "Indices: [" << answer4[0] << ", " << answer4[1] << "]\n";
    }
    else{
        cout << "No solution\n";
    }

}