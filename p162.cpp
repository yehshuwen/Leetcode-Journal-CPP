#include<vector>

using namespace std;

/*
162. Find Peak Element
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // O(log n) 不會找到真的最高峰
        int left = 0;
        int right = nums.size()-1;
        while(left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid]<nums[mid+1]) {
                left = mid+1;
            } else {
                right = mid;
            }
            return left;
        }
        // O(n) 會找到真的最高峰
        // int peak = nums[0];
        // int index = 0;
        // for (int i = 1; i< nums.size(); i++){
        //     if (nums[i] > peak) {
        //         peak = nums[i];
        //         index = i;
        //     }
        // }
        // return index;
    }
};