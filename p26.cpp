#include <vector>
#include <set>

using namespace std;
/*
26. Remove Duplicates from Sorted Array
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int slow = 0;
        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[slow] != nums[fast]){
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow+1;
        // set<int> s;
        // for (int i = 0; i < nums.size(); i++) {
        //     s.insert(nums[i]);
        // };
        // int index = 0;
        // for(int val: s) {
        //     nums[index] = val;
        //     index ++;
        // }
    
        // return s.size();
    }
};