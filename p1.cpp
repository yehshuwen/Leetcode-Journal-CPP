#include<vector>
#include<unordered_map>
#include<iostream>
/*
1. Two Sum
*/

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;

        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(hashmap.count(complement)) {
                return {hashmap[complement], i};
            }
            hashmap[nums[i]] = i;
        }
        return { };
    }
};


int main() {
    // 範例驗證：設定視窗大小為 3
    Solution sol;
    
    vector<int> nums = {2, 7, 11, 15};
    
    for (int index : sol.twoSum(nums, 9)) {
        cout << index << " ";
    }
    cout << endl;
    return 0;
}
